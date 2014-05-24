#ifndef LAC_DIFFERENCE_HELLINGER_H
#define LAC_DIFFERENCE_HELLINGER_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Hellinger : public Base<T> {
      DECLARE_VAL_T;
      T Diff(const va_t& a, const va_t& b) const {
	return std::pow(2.0, -0.5) * std::sqrt( std::pow(std::sqrt(a) - std::sqrt(b), 2.0).sum() );
      }
      Base<T>* Clone() const { return new Hellinger; }
    };
  }
}
#endif
