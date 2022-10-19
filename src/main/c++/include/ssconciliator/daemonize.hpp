// SPDX-License-Identifier: AGPL-3.0-only
/*
 * SSConciliator/src/main/c++/include/ssconciliator/daemonize.hpp
 *
 * Copyright (c) 2022 Awayume
 */

#pragma once

namespace ssconciliator {
  class Daemonize {
    public:
      static void init(void);
    private:
      Daemonize(void);
      static const int MAXFD;
      static void switch_process(void);
  };
};
