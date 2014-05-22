#ifndef LAC_GENERIC_FACTORY_H
#define LAC_GENERIC_FACTORY_H 1

#include <map>

namespace LAC {

  namespace Difference {

    template< typename K, typename T >
    class GenericFactory {
    public:
      template< class Iterator >
      GenericFactory(Iterator b, Iterator e) : m_map(b,e) {}
      ~GenericFactory(){
	for(it_t it = m_map.begin(); it != m_map.end(); ++it){
	  T* tmp = it->second;
	  it->second = 0;
	  if(tmp != 0)
	    delete tmp;
	}
      }
      T* Create(const K& key) const {
	typename map_t::const_iterator it = m_map.find(key);
	return it == m_map.end() ? 0 : it->second->Clone();
      }
    protected:
      typedef std::map<K,T*> map_t;
      typedef typename map_t::iterator it_t;
      map_t m_map;
    };

  }
}
#endif
