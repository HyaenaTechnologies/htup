#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// Path Environment Variable
const char *path_environment[2][14] = {
    "PATH=/usr/bin",
    (const char *)0
};

// Clone Error
const int clone_error = -1;
// Clone Succesful
const int clone_successful = 0;
// Fatal Error
const int fatal_error = 1;
// Program Succesful
const int program_successful = 0;

// APT Update
int aptUpdate(void) {
    // Clone Process
    int clone_process = fork();

    if (clone_process == clone_error) {
        perror("APT Update Failed - fork() = -1: \n");
        exit(fatal_error);
    };

    if (clone_process == clone_successful) {
        execle(
            "/usr/bin/sh", 
            "sh", 
            "-c",
            "apt update && apt -y full-upgrade",
            (const char *)0,
            path_environment
        );
    } else {
        waitpid(clone_process, NULL, 0);
    };
    
    return 0;
}

// Main
int main(void) {
    aptUpdate();
    exit(program_successful);
}