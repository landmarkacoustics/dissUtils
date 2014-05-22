#ifndef LAC_DIFFERENCE_CANBERRA_H
#define LAC_DIFFERENCE_CANBERRA_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Canberra : public Base<T> {
      typedef typename Base<T>::va_t va_t;
      T Diff(const va_t& a, const va_t& b) const {
	return (abs(a-b) / (abs(a) + abs(b))).sum();
      }
      // this gives a different result than R's dist algorithm
      // which uses ( abs(a - b) / abs(a + b) ).sum()
      // I like this better because it seems like a superior way
      // to handle entries with different signs

      Base<T>* Clone() const { return new Canberra; }
    };
  }
}
#endif
