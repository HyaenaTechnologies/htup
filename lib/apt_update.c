#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// Path Environment Variable
const char *environment[2][14] = {
    "PATH=/usr/bin",
    (const char *)0
};

// Update Ubuntu
int main(void) {
    const int apt_update = fork();

    if (apt_update == -1) {
        perror("APT Update Failed - fork(): \n");
        exit(1);
    };

    if (apt_update == 0) {
        execle(
            "/usr/bin/sh", 
            "sh", 
            "-c",
            "apt update && apt -y upgrade",
            (char *)0, 
            environment
        );
    } else {
        waitpid(apt_update, NULL, 0);
    };

    exit(0);
}