#ifndef LAC_DIFFERENCE_EQUALITY_H
#define LAC_DIFFERENCE_EQUALITY_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Equality : public Base<T> {
      DECLARE_VAL_T;
      T Diff(const va_t& a, const va_t& b) const {
	return (a==b).sum();
      }
      Base<T>* Clone() const { return new Equality; }
    };
  }
}
#endif
