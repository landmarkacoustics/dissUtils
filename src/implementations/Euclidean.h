#ifndef LAC_DIFFERENCE_EUCLIDEAN_H
#define LAC_DIFFERENCE_EUCLIDEAN_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Euclidean : public Base<T> {
      typedef typename Base<T>::va_t va_t;
      T Diff(const va_t& a, const va_t& b) const {
	return sqrt(pow(a - b, 2.0).sum());
      }
      Base<T>* Clone() const { return new Euclidean; }
    };
  }
}
#endif
