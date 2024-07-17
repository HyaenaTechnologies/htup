#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// Null Character Arrary Pointer
const char null_characters = (char *)0;

// Path Environment Variable
const char *path_environment[2][14] = {
    "PATH=/usr/bin",
    null_characters
};

// Program Termination State

const int fatal_error = 1;
const int program_successful = 0;

// APT Update
int main(void) {
    int clone_process = fork();
    const int clone_error = -1;
    const int clone_successful = 0;

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
            null_characters, 
            path_environment
        );
    } else {
        waitpid(clone_process, NULL, 0);
    };

    exit(program_successful);
}