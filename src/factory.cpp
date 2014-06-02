// Copyright (C) 2014 by Landmark Acoustics LLC

#include "differences.h"

namespace LAC {

  namespace Difference {

    const Factory*
    Factory::Factory::GetFactory()
    {
      static options_map_t optionsMap = make_options_map<key_t, double>();
      static Factory instance(optionsMap.begin(), optionsMap.end());
      return &instance;
    }
  }
}
