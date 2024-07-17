#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// Path Environment Variable
const char *environment[2][14] = {
    "PATH=/usr/bin",
    (const char *)0
};

// APT Update
int main(void) {
    const int apt_update = fork();
    const int fork_failed = -1;
    const int fork_successful = 0;

    if (apt_update == fork_failed) {
        perror("APT Update Failed - fork() = -1: \n");
        exit(1);
    };

    if (apt_update == fork_successful) {
        execle(
            "/usr/bin/sh", 
            "sh", 
            "-c",
            "apt update && apt -y full-upgrade",
            (char *)0, 
            environment
        );
    } else {
        waitpid(apt_update, NULL, 0);
    };

    exit(0);
}