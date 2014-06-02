#include "neighbors.h"

extern "C" {

  using namespace LAC;

  using namespace Difference;

  void two_matrix_neighbors(double *X, int *xdim,
			    double *Y, int *ydim,
			    char **method,
			    double *init_info, int *info_size,
			    int *n_neighbors,
			    double *OUT){

    const Factory* factory = Factory::GetFactory();

    val_t *F = factory->Create(*method);

    if(F != 0 && X != 0 && Y != 0){

      if(F->NeedsInitialization())
	F->Initialize(init_info, *info_size);

      RowMaker<double> rmx(xdim[0], xdim[1]), rmy(ydim[0], ydim[1]);

      std::vector<neigh_t> neighbor_v(rmx.Rows(),
				     neigh_t(*n_neighbors));

      val_t::va_t A(rmx.Cols()), B(rmy.Cols());

      rmx.SetBuffer(X);
      rmy.SetBuffer(Y);

      for(size_t i = 0; i < rmx.Rows(); ++i){

	rmx.GetRow(A, i);

	for(size_t j = 0; j < rmy.Rows(); ++j){

	  rmy.GetRow(B, j);

	  double tmp = F->Diff(A, B);

	  if(tmp > 0.0)
	    neighbor_v[i].Append(F->Diff(A, B));
	}
      }

      delete F;

      output_neighbors(neighbor_v, OUT);

    }
  }
}
