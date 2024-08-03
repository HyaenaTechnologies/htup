#include "documentation.h"
#include "system_upgrade.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Main
int main(int argumentNumber, char *arguments[], char *environmentVariables[]) {
  if (argumentNumber < 1) {
    printf("Command or Option Required:\n");
    printf("\n");
    usage();
  }

  while (arguments[1][0] == '-') {
    switch (arguments[1][1]) {
    case 'e':
      while (*environmentVariables != NULL) {
        printf("  %s\n", *(environmentVariables++));
      }
      break;

    case 'h':
      usage();
      break;

    case 'v':
      version();
      break;

    default:
      printf("Unknown Command or Option: %s\n", arguments[1]);
      printf("\n");
      usage();
    }

    ++arguments;
    --argumentNumber;
  }

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

  case *"sys":
    dnfSystemUpgrade();
    break;

  case *"yum":
    yumUpgrade();
    break;

  default:
    printf("Unknown Command or Option: %s\n", arguments[1]);
    printf("\n");
    usage();
  }

  return 0;
}
