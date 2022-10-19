// SPDX-License-Identifier: AGPL-3.0-only
/*
 * SSConciliator/src/main/c++/daemonize.cpp
 *
 * Copyright (c) 2022 Awayume
 */

#include <iostream>
#include <csignal>
#include <cstdlib>
#include <fcntl.h>
#include <sysexits.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ssconciliator/daemonize.hpp>

namespace ssconciliator {
  const int Daemonize::MAXFD = 64;

  void Daemonize::init(void) {
    Daemonize::switch_process();
    if (setsid() < 0) {
      std::exit(EXIT_FAILURE);
    }
    std::signal(SIGCHLD, SIG_IGN);
    std::signal(SIGHUP, SIG_IGN);
    Daemonize::switch_process();
    umask(0022);
    chdir("/");
    for (int i = 0; i < MAXFD; i++) {
      close(i);
    }
    int fd = open("/dev/null", O_RDWR, 0);
    if (fd < 0) {
      std::exit(EXIT_FAILURE);
    }
    else {
      dup2(fd, 0);
      dup2(fd, 1);
      dup2(fd, 2);
      if (fd < 2) {
        close(fd);
      }
    }
    return;
  }

  void Daemonize::switch_process(void) {
    pid_t pid = 0;
    pid = fork();
    if (pid < 0) {
      std::cout << "process fork error" << std::endl;
      std::exit(EXIT_FAILURE); // TODO: throw exception
    }
    else if (pid > 0) {
      _exit(0);
    }
    return;
  }
}
