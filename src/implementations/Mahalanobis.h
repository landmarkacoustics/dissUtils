#ifndef LAC_DIFFERENCE_MAHALANOBIS_H
#define LAC_DIFFERENCE_MAHALANOBIS_H 1
#include <cmath>
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Mahalanobis : public Base<T> {
      DECLARE_VAL_T;
    Mahalanobis() : m_cov(1) {}
      virtual bool NeedsInitialization() const { return true; }
      void Initialize(const T* buffer, size_t size) {
	if(size > 0)
	  m_cov = va_t(buffer, size);
      }
      T Diff(const va_t& a, const va_t& b) const {
	size_t n = a.size();
	va_t u = a - b, v(n);
	for(size_t i = 0; i < n; ++i){
	  c = m_cov[std::slice(i*n, n, 1)];
	  v[i] = (u * ca).sum();
	}
	return sqrt( (v * u).sum() );
      }
      Base<T>* Clone() const {
	Mahalanobis *m = new Mahalanobis;
	if(m_cov.size() > 0)
	  m->Initialize(&m_cov[0], m_cov.size());
	return m;
      }
    protected:
      va_t m_cov;
    };
  }
}
#endif
