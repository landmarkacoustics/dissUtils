#ifndef BNT_DIFFERENCE_MAHALANOBIS_H
#define BNT_DIFFERENCE_MAHALANOBIS_H 1
#include "../base.hpp"
namespace BNT {
  namespace Difference {
    template<typename T>
    struct Mahalanobis : public Base<T> {
      typedef typename Base<T>::va_t va_t;
      virtual bool NeedsInitialization() const { return true; }
      void Initialize(const T* buffer, size_t size) {
	m_cov = va_t(buffer, size);
      }
      T Diff(const va_t& a, const va_t& b) const {
	va_t u = a - b, v;
	for(size_t i = 0; i < u.size(); ++i)
	  v[i] = (u * m_cov[std::slice(i, u.size(), 1)]).sum();
	return sqrt( (v * u).sum() );
      }
      Base<T>* Clone() const {
	Mahalanobis *m = new Mahalanobis;
	m->Initialize(&(m_cov[0]), m_cov.size());
	return m;
      }
    protected:
      va_t m_cov;
    };
  }
}
#endif
