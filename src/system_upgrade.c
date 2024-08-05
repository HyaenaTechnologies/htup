#include "program_status.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// Path Environment Variable
const char *pathEnvironment[2][14] = {
    "PATH=/usr/bin",
    (const char *)0};
// Shell Path
const char shellPath[12] = "/usr/bin/sh";
// Shell Binary
const char shellBinary[3] = "sh";
// Shell Command Flag
const char shellCommandFlag[3] = "-c";

// Clone Error
const int cloneError = -1;
// Clone Succesful
const int cloneSuccessful = 0;

// APT Upgrade
void aptUpgrade(void) {
  // Clone Process
  int cloneProcess = fork();

  if (cloneProcess == cloneError) {
    perror("APT Upgrade Failed - fork() = -1: \n");
    exit(FATAL_ERROR);
  };

  if (cloneProcess == cloneSuccessful) {
    execle(
        shellPath,
        shellBinary,
        shellCommandFlag,
        "apt update && apt -y full-upgrade",
        (const char *)0,
        pathEnvironment);
  } else {
    waitpid(cloneProcess, NULL, 0);
  };

  exit(PROGRAM_SUCCESSFUL);
}

// Distribution Release Upgrade
void distributionUpgrade(void) {
  // Clone Process
  int cloneProcess = fork();

  if (cloneProcess == cloneError) {
    perror("Ubuntu Upgrade Failed - fork() = -1: \n");
    exit(FATAL_ERROR);
  };

  if (cloneProcess == cloneSuccessful) {
    execle(
        shellPath,
        shellBinary,
        shellCommandFlag,
        "do-release-upgrade",
        (const char *)0,
        pathEnvironment);
  } else {
    waitpid(cloneProcess, NULL, 0);
  };

  exit(PROGRAM_SUCCESSFUL);
}

// DNF Upgrade
void dnfUpgrade(void) {
  // Clone Process
  int cloneProcess = fork();

  if (cloneProcess == cloneError) {
    perror("DNF Upgrade Failed - fork() = -1: \n");
    exit(FATAL_ERROR);
  };

  if (cloneProcess == cloneSuccessful) {
    execle(
        shellPath,
        shellBinary,
        shellCommandFlag,
        "dnf --refresh -y upgrade",
        (const char *)0,
        pathEnvironment);
  } else {
    waitpid(cloneProcess, NULL, 0);
  };

  exit(PROGRAM_SUCCESSFUL);
}

// DNF System Upgrade
void dnfSystemUpgrade(void) {
  // Clone Process
  int cloneProcess = fork();

  if (cloneProcess == cloneError) {
    perror("DNF System Upgrade Failed - fork() = -1: \n");
    exit(FATAL_ERROR);
  };

  if (cloneProcess == cloneSuccessful) {
    execle(
        shellPath,
        shellBinary,
        shellCommandFlag,
        "dnf system-upgrade download --releasever=40",
        (const char *)0,
        pathEnvironment);
  } else {
    waitpid(cloneProcess, NULL, 0);
  };

  exit(PROGRAM_SUCCESSFUL);
}

// YUM Upgrade
void yumUpgrade(void) {
  // Clone Process
  int cloneProcess = fork();

  if (cloneProcess == cloneError) {
    perror("YUM Upgrade Failed - fork() = -1: \n");
    exit(FATAL_ERROR);
  };

  if (cloneProcess == cloneSuccessful) {
    execle(
        shellPath,
        shellBinary,
        shellCommandFlag,
        "yum -y upgrade",
        (const char *)0,
        pathEnvironment);
  } else {
    waitpid(cloneProcess, NULL, 0);
  };

  exit(PROGRAM_SUCCESSFUL);
}
