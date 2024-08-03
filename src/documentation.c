#include "program_status.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Usage
void usage(void) {
  printf("Usage: htup [command] [options]\n");
  printf("\n");
  printf("Commands:\n");
  printf("\n");
  printf("apt             APT Full Upgrade\n");
  printf("dnf             DNF Upgrade\n");
  printf("release         Ubuntu Release Upgrade\n");
  printf("sys             Fedora Release Upgrade\n");
  printf("yum             YUM Upgrade\n");
  printf("\n");
  printf("Options:\n");
  printf("\n");
  printf("-e              Print Environment Variables\n");
  printf("-h              Print Command Usage\n");
  printf("-v              Print Version Number\n");

  exit(PROGRAM_SUCCESSFUL);
}

// Version
void version(void) {
  printf("htup - Version: 0.2.0\n");

  exit(PROGRAM_SUCCESSFUL);
}
