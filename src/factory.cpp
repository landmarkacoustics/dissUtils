#include "differences.h"

namespace LAC {

  namespace Difference {

    Factory* MakeFactory() {

      options_map_t optionsMap = make_options_map<key_t, double>();

      return new Factory(optionsMap.begin(), optionsMap.end());

    }
  }
}
