#include "documentation.h"
#include "system_upgrade.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

// Main
int main(int argumentNumber, char *arguments[], char *environmentVariables[]) {
  if (argumentNumber < 1) {
    printf("Command or Option Required:\n");
    printf("\n");
    usage();
  } else {
    switch (*arguments[1]) {
    case *"apt":
      aptUpgrade();
      break;

    case *"dnf":
      dnfUpgrade();
      break;

    case *"release":
      distributionUpgrade();
      break;

    case *"yum":
      yumUpgrade();
      break;

    default:
      printf("Unknown Command or Option: %s\n", arguments[1]);
      printf("\n");
      usage();
    }
  }

  while (arguments[0][1] == *"--") {
    switch (arguments[1][1]) {
    case *"env":
      while (*environmentVariables != NULL) {
        printf("  %s\n", *(environmentVariables++));
      }
      break;

    case *"help":
      usage();
      break;

    case *"sys":
      dnfSystemUpgrade();
      ;
      break;

    case *"version":
      version();
      break;

    default:
      printf("Unknown Command or Option: %s\n", arguments[1]);
      printf("\n");
      usage();
    }
  }

  return 0;
}
