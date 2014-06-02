#include "neighbors.h"

extern "C" {

  using namespace LAC;

  using namespace Difference;

  void neighbors(double *IN, int *dim,

		 char **method,

		 double *init_info, int *info_size,

		 int *n_neighbors,

		 double *OUT){

    const Factory* factory = Factory::GetFactory();

    val_t *F = factory->Create(*method);

    if(F != 0 && IN != 0){

      if(F->NeedsInitialization())
	F->Initialize(init_info, *info_size);

      RowMaker<double> rm(dim[0], dim[1]);

      std::vector<neigh_t> neighbor_v(rm.Rows(),
				      neigh_t(*n_neighbors));

      val_t::va_t A(rm.Cols()), B(rm.Cols());

      rm.SetBuffer(IN);

      for(size_t i = 0; i < rm.Rows(); ++i){

	rm.GetRow(A, i);

	for(size_t j = i + 1; j < rm.Rows(); ++j){

	  rm.GetRow(B, j);

	  double delta = F->Diff(A, B);

	  neighbor_v[i].Append(delta);

	  neighbor_v[j].Append(delta);
	}
      }

      delete F;

      output_neighbors(neighbor_v, OUT);
    }
  }

}

