#include <stdlib.h>
#include <unistd.h>
#include "system_upgrade.h"

// Program Succesful
const int programSuccessful = 0;

// Main
int main(int argumentNumber, char *arguments[], char *environmentVariables[]) {
    aptUpgrade();
    exit(programSuccessful);
}
