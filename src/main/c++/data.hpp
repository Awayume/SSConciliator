// SPDX-License-Identifier: AGPL-3.0-only
/*
 * SSConciliator/src/main/c++/data.hpp
 *
 * Copyright (c) 2022 Awayume
 */

#pragma once
#include "argument.hpp"

namespace ssconciliator {
  class Data {
    public:
      static const argument_map commands;
      static const argument_map options;
      static const argument_map short_options;
  };
}
