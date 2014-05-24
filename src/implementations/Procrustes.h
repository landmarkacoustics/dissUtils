#ifndef LAC_DIFFERENCE_PROCRUSTES_H
#define LAC_DIFFERENCE_PROCRUSTES_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Procrustes : public Base<T> {
      DECLARE_VAL_T;
      Procrustes() : m_cols(1u) {}
      ~Procrustes() {}
      virtual bool NeedsInitialization() const { return true; }
      virtual void Initialize(const T* buffer, size_t size) {
	if(size > 0)
	  m_cols = buffer[0];
      }
      T Diff(const va_t& a, const va_t& b) const {
	size_t nr = a.size() / m_cols;
	T d = 0.0;
	for(size_t i = 0; i < nr; ++i){
	  std::slice ix(i, m_cols, nr);
	  d += std::sqrt( std::pow(a[ix] - b[ix], 2.0).sum() );
	}
	return d;
      }
      Base<T>* Clone() const {
	Procrustes *p = new Procrustes;
	T tmp = m_cols;
	p->Initialize(&tmp, 1);
	return p;
      }
    protected:
      size_t m_cols;
    };
  }
}
#endif
