#ifndef LAC_DIFFERENCE_NEIGHBORS_H
#define LAC_DIFFERENCE_NEIGHBORS_H 1

#include "differences.h"
#include "neighbor_set.h"

#include <vector>

namespace LAC {

  namespace Difference {

    typedef NeighborSet<double> neigh_t;

    template<typename T>
    void output_neighbors(const std::vector< NeighborSet<T> >& neighbor_v,
			  T* OUT){

      typedef std::vector< NeighborSet<T> > vec_t;

      size_t k = 0;

      for(size_t i = 0; i < neighbor_v.size(); ++i){

	size_t j = 0;

	for(typename neigh_t::const_it_t it = neighbor_v[i].Begin();
	    it != neighbor_v[i].End();
	    ++it){

	  OUT[k++] = *it;

	  j++;
	}
	// ensures that OUT is filled correctly, even if some point has fewer than m_count neighbor_v!
	k += neighbor_v[i].m_count - j;
      }
    }

  }
}

#endif
