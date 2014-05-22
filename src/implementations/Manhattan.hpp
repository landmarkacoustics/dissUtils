#ifndef BNT_DIFFERENCE_MANHATTAN_H
#define BNT_DIFFERENCE_MANHATTAN_H 1
#include "../base.hpp"
namespace BNT {
  namespace Difference {
    template<typename T>
    struct Manhattan : public Base<T> {
      typedef typename Base<T>::va_t va_t;
      T Diff(const va_t& a, const va_t& b) const {
	return abs(a - b).sum();
      }
      Base<T>* Clone() const { return new Manhattan; }
    };
  }
}
#endif
