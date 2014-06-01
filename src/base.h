#ifndef LAC_DIFFERENCE_BASE_H
#define LAC_DIFFERENCE_BASE_H 1

#include <valarray>
#include <limits>

#define DECLARE_VAL_T typedef typename Base<T>::va_t va_t

namespace LAC {

  namespace Difference {

    template< typename T>
      struct Base {
	typedef std::valarray<T> va_t;
	Base(){}
	virtual ~Base() {}
	virtual bool NeedsInitialization() const { return false; }
	virtual void Initialize(const T* buffer, size_t size) {}
	virtual T Diff(const va_t& a, const va_t& b) const { return NaN(); }
	virtual Base* Clone() const { return 0; }
      protected:
	static const T& NaN() {
	  static const T nan =  std::numeric_limits<T>::quiet_NaN();
	  return nan;
	}
      };
  }
}

#endif
