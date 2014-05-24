#ifndef LAC_DIFFERENCE_PEARSON_H
#define LAC_DIFFERENCE_PEARSON_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Pearson : public Base<T> {
      typedef typename Base<T>::va_t va_t;
      T Diff(const va_t& a, const va_t& b) const {

	T abar = 0, bbar = 0, Cov = 0, atwo = 0, btwo = 0;

	for(size_t n = 0; n < a.size(); ++n){

	  T d = 1.0 / (n + 1.0), da = a[n] - abar, db = b[n] - bbar;

	  Cov += d * n * da * db;

	  abar += d * da;

	  bbar += d * db;

	  atwo += da * (a[n] - abar);

	  btwo += db * (b[n] - bbar);

	}

	return Cov / ( std::sqrt(atwo) * std::sqrt(btwo) );
      }
      Base<T>* Clone() const { return new Pearson; }
    };
  }
}
#endif
