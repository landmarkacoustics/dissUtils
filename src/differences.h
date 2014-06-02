#ifndef LAC_DIFFERENCES_H
#define LAC_DIFFERENCES_H 1

#include <string>

#include "options.h"
#include "generic_factory.h"
#include "row_maker.h"

namespace LAC {

  namespace Difference {

    typedef std::string key_t;

    typedef Base<double> val_t;

    typedef std::map<key_t, val_t*> options_map_t;

    class Factory : public GenericFactory<key_t, val_t> {
    public:
      static const Factory* GetFactory();
    private:
      template< class Iterator >
	Factory(Iterator b, Iterator e) : GenericFactory<key_t, val_t>(b,e) {}
      Factory(Factory const&);
      void operator=(Factory const&);
    };

  }
}

#endif
