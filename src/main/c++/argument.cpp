// SPDX-License-Identifier: APGL-3.0-only
/*
 * SSConciliator/src/main/c++/argument.cpp
 *
 * Copyright (c) 2022 Awayume
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include "data.hpp"
#include "argument.hpp"

namespace ssconciliator {
  cmdline ArgumentParser::parse(int argc, char* argv[]) {
    argument_map commands, options;
    std::string arg, value, argp;
    for (int i = 0; i < argc; i++) {
      if (i == 0) {
        continue;
      }
      arg = std::string(argv[i]);
      if (i + 1 != argc) {
        value = std::string(argv[i+1]);
      }
      else {
        value = "";
      }
      if (value.rfind("-", 0) == 0) {
        value = "";
      }
      if (arg.rfind("-", 0) != 0) {
        try {
          Data::commands.at(arg);
          commands[arg] = value;
        }
        catch (std::out_of_range&) {
          if (std::string(argv[i-1]).rfind("-", 0) != 0) {
            throw std::runtime_error("Invalid command: " + arg);
          }
        }
      }
      else if (arg.rfind("--", 0) == 0) {
        argp = arg.substr(2);
        try {
          Data::options.at(argp);
          options[argp] = value;
        }
        catch (std::out_of_range&) {
          throw std::runtime_error("Invalid option: " + arg);
        }
      }
      else if (arg.rfind("-", 0) == 0) {
        argp = arg.substr(1);
        try {
          auto key = Data::short_options.at(argp);
          options[key] = value;
        }
        catch (std::out_of_range&) {
          throw std::runtime_error("Invalid option: " + arg);
        }
      }
    }
    return {commands, options};
  }
}
