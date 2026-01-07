// Process creation with fork()
// Demonstrates parent-child process relationships

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    printf("Before fork(): PID = %d\n", getpid());

    pid = fork();

    if (pid < 0)
    {
        // Fork failed
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process: PID = %d, Parent PID = %d\n",
               getpid(), getppid());
        printf("Child is doing some work...\n");
        sleep(2);
        printf("Child process completed\n");
        exit(42); // Exit with status 42
    }
    else
    {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n",
               getpid(), pid);
        printf("Parent waiting for child...\n");

        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }

        printf("Parent process completed\n");
    }

    return 0;
}