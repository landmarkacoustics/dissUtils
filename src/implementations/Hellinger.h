#ifndef BNT_DIFFERENCE_HELLINGER_H
#define BNT_DIFFERENCE_HELLINGER_H 1
#include "../base.h"
namespace BNT {
  namespace Difference {
    template<typename T>
    struct Hellinger : public Base<T> {
      typedef typename Base<T>::va_t va_t;
      T Diff(const va_t& a, const va_t& b) const {
	return pow(2.0, -0.5) * sqrt( pow(sqrt(a) - sqrt(b), 2.0).sum() );
      }
      Base<T>* Clone() const { return new Hellinger; }
    };
  }
}
#endif
