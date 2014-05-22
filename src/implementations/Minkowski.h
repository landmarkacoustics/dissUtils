#ifndef BNT_DIFFERENCE_MINKOWSKI_H
#define BNT_DIFFERENCE_MINKOWSKI_H 1
#include "../base.h"
namespace BNT {
  namespace Difference {
    template<typename T>
    struct Minkowski : public Base<T> {
      typedef typename Base<T>::va_t va_t;
      Minkowski() : m_p(2.0), m_q(0.5) {}
      ~Minkowski() {}
      //    virtual bool NeedsInitialization() const { return true; }
      void Initialize(const T* buffer, size_t size) {
	if(size > 0){
	  m_p = buffer[0];
	  m_q = 1.0 / m_p;
	}
      }
      T Diff(const va_t& a, const va_t& b) const {
	return pow(pow(a - b, m_p).sum(), m_q);
      }
      Base<T>* Clone() const {
	Minkowski* m = new Minkowski;
	m->Initialize(&m_p, 1);
	return m;
      }
    protected:
      T m_p;
      T m_q;
    };
  }
}
#endif
