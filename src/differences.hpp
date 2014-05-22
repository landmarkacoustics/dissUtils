#ifndef BNT_DIFFERENCES_H
#define BNT_DIFFERENCES_H 1

#include <string>

#include "options.hpp"
#include "generic_factory.hpp"
#include "row_maker.hpp"

namespace BNT {

  namespace Difference {

    typedef std::string key_t;

    typedef Base<double> val_t;

    typedef std::map<key_t, val_t*> options_map_t;

    typedef GenericFactory<key_t, val_t> Factory;

    Factory* MakeFactory();
  }
}

#endif
