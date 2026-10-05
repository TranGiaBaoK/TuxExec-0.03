#include "kill.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void kill_proc_execvp(void) {
    char pid_str[16];
    printf("Enter PID to kill: ");
    if (scanf("%15s", pid_str) != 1) {
        printf("Invalid PID!\n");
        return;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("[-] Fork failed");
        return;
    }

    if (pid == 0) {
        char *args[] = {"kill", "-9", pid_str, NULL};
        execvp("kill", args);
        perror("[-] execvp failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("[+] Process %s killed via execvp.\n", pid_str);
        } else {
            printf("[-] Failed to kill process %s.\n", pid_str);
        }
    }
}
