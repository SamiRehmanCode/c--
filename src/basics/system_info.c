// System calls demonstration
// Shows basic system programming concepts

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("System Programming Basics\n");
    printf("========================\n\n");

    // Display process information
    printf("Process ID (PID): %d\n", getpid());
    printf("Parent Process ID (PPID): %d\n", getppid());

    // Display user information
    printf("User ID (UID): %d\n", getuid());
    printf("Effective User ID: %d\n", geteuid());

    // Working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("Current working directory: %s\n", cwd);
    }

    return 0;
}