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
// Fatal Error
const int fatalError = 1;
// Program Succesful
const int programSuccessful = 0;

// APT Update
int aptUpdate(void) {
    // Clone Process
    int cloneProcess = fork();

    if (cloneProcess == cloneError) {
        perror("APT Update Failed - fork() = -1: \n");
        exit(fatalError);
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

    return 0;
}

// Main
int main(void) {
    aptUpdate();
    exit(programSuccessful);
}