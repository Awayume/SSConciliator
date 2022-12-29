// SPDX-License-Identifier: APGL-3.0-only
/*
 * SSConciliator/src/main/c++/data.cpp
 *
 * Copyright (c) 2022 Awayume
 */

#include "argument.hpp"
#include "data.hpp"

namespace ssconciliator {
  const argument_map Data::commands = {

  };
  const argument_map Data::options = {
    {"test", "Enable test mode"},
  };
  const argument_map Data::short_options = {
    {"t", "test"},
  };
}
