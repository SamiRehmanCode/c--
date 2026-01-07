// Pipe communication example
// Demonstrates inter-process communication using pipes

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

int main()
{
    int pipefd[2]; // File descriptors for pipe
    pid_t pid;
    char buffer[BUFFER_SIZE];
    char message[] = "Hello from parent process!";

    // Create pipe
    if (pipe(pipefd) == -1)
    {
        perror("pipe failed");
        exit(1);
    }

    // Create child process
    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process (reader)
        close(pipefd[1]); // Close write end

        printf("Child: Reading from pipe...\n");

        ssize_t bytes_read = read(pipefd[0], buffer, BUFFER_SIZE - 1);
        if (bytes_read > 0)
        {
            buffer[bytes_read] = '\0'; // Null terminate
            printf("Child: Received message: \"%s\"\n", buffer);
        }

        close(pipefd[0]); // Close read end
        exit(0);
    }
    else
    {
        // Parent process (writer)
        close(pipefd[0]); // Close read end

        printf("Parent: Sending message through pipe...\n");

        write(pipefd[1], message, strlen(message));

        close(pipefd[1]); // Close write end

        // Wait for child to complete
        wait(NULL);

        printf("Parent: Communication completed\n");
    }

    return 0;
}