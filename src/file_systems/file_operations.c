// File I/O operations demonstration
// Shows various file system operations

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    const char *filename = "test_file.txt";
    const char *content = "This is a test file for system programming!\nLine 2\nLine 3\n";
    int fd;
    char buffer[256];
    struct stat file_stat;

    printf("File System Operations Demo\n");
    printf("===========================\n\n");

    // 1. Create and write to file
    printf("1. Creating file '%s' and writing content...\n", filename);
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open for writing failed");
        exit(1);
    }

    ssize_t bytes_written = write(fd, content, strlen(content));
    printf("   Wrote %zd bytes to file\n", bytes_written);
    close(fd);

    // 2. Read from file
    printf("\n2. Reading file content...\n");
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open for reading failed");
        exit(1);
    }

    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';
        printf("   File content:\n%s", buffer);
    }
    close(fd);

    // 3. Get file statistics
    printf("\n3. File statistics:\n");
    if (stat(filename, &file_stat) == 0)
    {
        printf("   File size: %ld bytes\n", file_stat.st_size);
        printf("   File permissions: %o\n", file_stat.st_mode & 0777);
        printf("   Number of links: %ld\n", file_stat.st_nlink);
    }

    // 4. Clean up
    printf("\n4. Removing test file...\n");
    if (unlink(filename) == 0)
    {
        printf("   File '%s' removed successfully\n", filename);
    }
    else
    {
        perror("unlink failed");
    }

    return 0;
}