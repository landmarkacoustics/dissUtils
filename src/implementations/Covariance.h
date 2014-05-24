#ifndef LAC_DIFFERENCE_COVARIANCE_H
#define LAC_DIFFERENCE_COVARIANCE_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Covariance : public Base<T> {
      DECLARE_VAL_T;
      T Diff(const va_t& a, const va_t& b) const {

	T abar = 0, bbar = 0, Cov = 0;

	for(size_t n = 0; n < a.size(); ++n){

	  T d = 1.0 / (n + 1.0);

	  Cov += d * n * (a[n] - abar) * (b[n] - bbar);

	  abar += d * (a[n] - abar);

	  bbar += d * (b[n] - bbar);

	}

	return Cov / (a.size() - 1);  
      }
      Base<T>* Clone() const { return new Covariance; }
    };
  }
}
#endif
