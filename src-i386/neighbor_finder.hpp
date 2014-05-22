#include <vector>
#include <iterator>

namespace BNT {

  template <typename NeighborElement, typename DistanceFunctor>
  class NeighborFinder : public DistanceFunctor {

  public:

    typedef std::vector<NeighborElement> result_t;

    typedef typename NeighborElement::data_t nel_t;

    NeighborFinder(size_t n_neighbors)
    : DistanceFunctor(),
      m_count(n_neighbors)
    {}

    ~NeighborFinder(){}

    typename result_t::const_iterator Begin() const { return m_neighbors.begin(); }

    typename result_t::const_iterator End() const { return m_neighbors.end(); }

    template<typename Iterator>
    void FindAmong(const Iterator b, const Iterator e){

      size_t i, j, n = std::distance(b,e);

      m_neighbors.resize(n, NeighborElement(m_count));

      Iterator it, jt;

      for(it = b, i = 0; it != e; ++it, ++i){

	jt = it;

	for(std::advance(jt, 1), j = i + 1; jt != e; ++jt, ++j){

	  // this lets one use std::pair<double, size_t> for the element
	  nel_t tmp(DistanceFunctor::Diss(*it, *jt), j);

	  m_neighbors[i].Append(tmp);

	  tmp.second = i;

	  m_neighbors[j].Append(tmp);

	}
      }
    }

    void FillVectors(int *indices, double *dists){

      for(size_t tmp = 0, typename result_t::iterator it = Begin(); it != End(); ++it){

	for(size_t j = 0; j < (*it).m_queue.size(); ++j, ++tmp){

	  const nel_t& temp = (*it).m_queue[j];

	  indices[tmp] = temp.second;

	  dists[tmp] = temp.first;
	}
      }
    }
  protected:

    size_t m_count;

    result_t m_neighbors;
  };

}
