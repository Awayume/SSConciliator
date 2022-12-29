// SPDX-License-Identifier: AGPL-3.0-only
/*
 * SSConciliator/src/main/c++/main.c
 *
 * Copyright (c) 2022 Awayume
 */

#include <iostream>
#include <ssconciliator/daemonize.hpp>
#include "argument.hpp"

int main(int argc, char* argv[]) {
  using std::cout;
  using std::endl;
  cout << "SSConciliator" << endl;
  ssconciliator::cmdline args = ssconciliator::ArgumentParser::parse(argc, argv);
  ssconciliator::Daemonize::init();
  return 0;
}
