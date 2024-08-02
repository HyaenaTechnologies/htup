#include "documentation.h"
#include "system_upgrade.h"
#include <stdio.h>
#include <unistd.h>

// Main
int main(int argumentNumber, char *arguments[], char *environmentVariables[]) {
  while ((argumentNumber > 1) && (arguments[1][0] == *"--")) {
    switch (*arguments[1]) {
    case * "apt":
      aptUpgrade();
      break;

    case * "dnf":
      dnfUpgrade();
      break;

    case * "release":
      distributionUpgrade();
      break;

    case * "yum":
      yumUpgrade();
      break;

    default:
      printf("Unknown Argument: %s\n", arguments[1]);
      usage();
    }

    ++arguments;
    --argumentNumber;
  }

  return 0;
}
