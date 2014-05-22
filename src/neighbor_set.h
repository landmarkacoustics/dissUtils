#ifndef LAC_DIFFERENCE_NEIGHBOR_SET_H
#define LAC_DIFFERENCE_NEIGHBOR_SET_H 1

#include <utility>
#include <list>
#include <algorithm>

namespace LAC {

  namespace Difference {

    template<typename T>
    struct NeighborSet {
      typedef T data_t;
      typedef std::list<T> queue_t;
      typedef typename queue_t::iterator it_t;
      typedef typename queue_t::const_iterator const_it_t;
      NeighborSet(size_t count) : m_count(std::max((size_t)1,count)) {}
      ~NeighborSet(){}
      void Append(const T& d){
	it_t it = std::lower_bound(m_queue.begin(),
				   m_queue.end(),
				   d);

	m_queue.insert(it, d);

	if(m_queue.size() > m_count)
	  m_queue.pop_back();
      }
      const_it_t Begin() const { return m_queue.begin(); }
      const_it_t End() const { return m_queue.end(); }

      size_t m_count;
      queue_t m_queue;
    };

  }
}
#endif
