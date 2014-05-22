#include "differences.h"

extern "C" {

  using namespace LAC;

  using namespace Difference;

  void two_matrix_differences(double *X, int *xdim,
			      double *Y, int *ydim,
			      char **method,
			      double *init_info, int *info_size,
			      double *OUT){

    Factory* factory = MakeFactory();

    val_t *F = factory->Create(*method);

    if(F != 0 && X != 0 && Y != 0){

      if(F->NeedsInitialization())
	F->Initialize(init_info, *info_size);

      RowMaker<double> rmx(xdim[0], xdim[1]), rmy(ydim[0], ydim[1]);

      val_t::va_t A(rmx.Cols()), B(rmy.Cols());

      rmx.SetBuffer(X);
      rmy.SetBuffer(Y);

      size_t k = 0;

      for(size_t i = 0; i < rmx.Rows(); ++i){

	rmx.GetRow(A, i);

	for(size_t j = 0; j < rmy.Rows(); ++j){

	  rmy.GetRow(B, j);

	  OUT[k++] = F->Diff(A, B);
	}
      }

      delete F;
    }
    else
      OUT[0] = -3.14;

    delete factory;
  }
}
