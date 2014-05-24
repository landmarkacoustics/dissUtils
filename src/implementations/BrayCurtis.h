#ifndef LAC_DIFFERENCE_BRAYCURTIS_H
#define LAC_DIFFERENCE_BRAYCURTIS_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct BrayCurtis : public Base<T> {
      DECLARE_VAL_T;
      T Diff(const va_t& a, const va_t& b) const {
	T S = a.sum()+b.sum(), C = 0;
	for(size_t i = 0; i < a.size(); ++i)
	  C += std::min(a[i], b[i]);
	return 1.0 - 2 * C / S;
      }
      Base<T>* Clone() const { return new BrayCurtis; }
    };
  }
}
#endif
