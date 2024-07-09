#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

const char *environment[2] = {
    "PATH=/usr/bin",
    (char *)0
};

int main(void) {
    const int apt_update = fork();

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

    if (apt_update == -1) {
        perror("APT Update Failed - fork(): ");
        return 1;
    };

    return 0; 
}