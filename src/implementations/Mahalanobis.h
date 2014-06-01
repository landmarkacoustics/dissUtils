#ifndef LAC_DIFFERENCE_MAHALANOBIS_H
#define LAC_DIFFERENCE_MAHALANOBIS_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
      struct Mahalanobis : public Base<T> {
      DECLARE_VAL_T;
      Mahalanobis() {}
      virtual bool NeedsInitialization() const { return true; }
      void Initialize(const T* buffer, size_t size) {
	m_cov = va_t(buffer, size);
      }
      T Diff(const va_t& a, const va_t& b) const {
	size_t n = a.size();
	if( m_cov.size() == n * n){
	  va_t u = a - b, v(n);
	  for(size_t i = 0; i < n; ++i){
	    va_t tmp = m_cov[std::slice(i * n, n, 1)];
	    tmp *= u;
	    v[i] = u.sum();
	  }
	  return std::sqrt( (u * v).sum() );
	}
	return Base<T>::NaN();
      }
      Base<T>* Clone() const {
	Mahalanobis *m = new Mahalanobis;
	m->m_cov = m_cov;
	return m;
      }
    protected:
      va_t m_cov;
    };
  }
}
#endif
