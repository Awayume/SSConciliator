// SPDX-License-Identifier: AGPL-3.0-only
/*
 * SSConciliator/src/main/c++/argument.hpp
 *
 * Copyright (c) 2022 Awayume
 */

#pragma once
#include <string>
#include <unordered_map>
#include <utility>

namespace ssconciliator {
  using argument_map = std::unordered_map<std::string, std::string>;
  using cmdline = std::pair<argument_map, argument_map>;

  class ArgumentParser {
    public:
      static cmdline parse(int argc, char* argv[]);
  };
}
