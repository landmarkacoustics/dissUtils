#include "differences.h"

extern "C" {

  using namespace LAC;

  using namespace Difference;

  void differences(double *IN, int *dim,

		   char **method,

		   double *init_info, int *info_size,

		   double *OUT){

    const Factory* factory = Factory::GetFactory();

    val_t *F = factory->Create(*method);

    if(F != 0 && IN != 0){

      if(F->NeedsInitialization())

	F->Initialize(init_info, *info_size);

      RowMaker<double> rm(dim[0], dim[1]);

      val_t::va_t A(rm.Cols()), B(rm.Cols());

      rm.SetBuffer(IN);

      size_t k = 0;

      for(size_t i = 0; i < rm.Rows(); ++i){

	rm.GetRow(A, i);

	for(size_t j = i + 1; j < rm.Rows(); ++j){

	  rm.GetRow(B, j);

	  OUT[k++] = F->Diff(A, B);
	}
      }
      delete F;
    }
    else
      OUT[0] = -3.14;
  }
}
