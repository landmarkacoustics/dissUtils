#ifndef BNT_DIFFERENCES_ROWMAKER_H
#define BNT_DIFFERENCES_ROWMAKER_H 1

#include "base.h"

namespace BNT {

  namespace Difference {

    template< typename T >
    class RowMaker {
    public:
      RowMaker(size_t nrow = 1, size_t ncol = 1) :
	m_rows(nrow),
	m_cols(ncol),
	m_buffer(0)
      {}
      ~RowMaker(){ SetBuffer(0); }
      size_t Rows() const { return m_rows; }
      size_t Cols() const { return m_cols; }
      void SetBuffer(const T* buffer){m_buffer = buffer;}
      void GetRow(typename Base<T>::va_t& V, size_t i) const {
	V.resize(m_cols);
	for(size_t j = 0; j < m_cols; ++j)
	  V[j] = m_buffer[i + m_rows * j];
      }
    protected:
      size_t m_rows;
      size_t m_cols;
      const T* m_buffer;
    };
  }
}

#endif
