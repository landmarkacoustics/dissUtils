#ifndef LAC_DIFFERENCE_CHEBYSHEV_H
#define LAC_DIFFERENCE_CHEBYSHEV_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Chebyshev : public Base<T> {
      typedef typename Base<T>::va_t va_t;
      T Diff(const va_t& a, const va_t& b) const {
	return abs(a - b).max();
      }
      Base<T>* Clone() const { return new Chebyshev; }
    };
  }
}
#endif
