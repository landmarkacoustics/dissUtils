#ifndef BNT_DIFFERENCE_BASE_H
#define BNT_DIFFERENCE_BASE_H 1

#include <valarray>

#define DECLARE_VAL_T typedef typename Base<T>::va_t va_t

namespace BNT {

  namespace Difference {

    template< typename T>
    struct Base {
      typedef std::valarray<T> va_t;
      Base(){}
      virtual ~Base() {}
      virtual bool NeedsInitialization() const { return false; }
      virtual void Initialize(const T* buffer, size_t size) {}
      virtual T Diff(const va_t& a, const va_t& b) const { return nan; }
      virtual Base* Clone() const { return 0; }
    protected:
      static const T nan;
    };

    template<typename T>
    const T Base<T>::nan = 0.0 / 0.0;
  }
}

#endif
