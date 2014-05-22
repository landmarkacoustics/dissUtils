#ifndef LAC_DIFFERENCE_JACCARD_H
#define LAC_DIFFERENCE_JACCARD_H 1
#include "../base.h"
namespace LAC {
  namespace Difference {
    template<typename T>
    struct Jaccard : public Base<T> {
      typedef typename Base<T>::va_t va_t;
      Jaccard() : m_eps(1e-9) {}
      ~Jaccard() {}
      //    virtual bool NeedsInitialization() const { return true; }
      void Initialize(const T* buffer, size_t size) {
	if(size > 0)
	  m_eps = buffer[0];
      }
      T Diff(const va_t& a, const va_t& b) const {
	T some = a.size(), both = 0;
	for(size_t i = 0; i < a.size(); ++i){
	  T tmpa = abs(a[i]), tmpb = abs(b[i]);
	  if(tmpa < m_eps && tmpb < m_eps)
	    some--;
	  else
	    if(tmpa > m_eps && tmpb > m_eps)
	      both++;
	}
	return (some - both) / (T)some;
      }
      Base<T>* Clone() const {
	Jaccard *j = new Jaccard;
	j->Initialize(&m_eps, 1);
	return j;
      }
    protected:
      T m_eps;
    };
  }
}
#endif
