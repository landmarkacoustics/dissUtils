#ifndef LAC_DIFFERENCE_CHEBYSHEV_H
#define LAC_DIFFERENCE_CHEBYSHEV_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Chebyshev : public Base<T> {
      DECLARE_VAL_T;
      T Diff(const va_t& a, const va_t& b) const {
	return std::abs(a - b).max();
      }
      Base<T>* Clone() const { return new Chebyshev; }
    };
  }
}
#endif
