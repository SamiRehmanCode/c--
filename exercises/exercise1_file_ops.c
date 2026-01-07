/*
 * Exercise 1: Basic File Operations
 *
 * Problem: Create a program that performs the following operations:
 * 1. Create a file named "student_data.txt"
 * 2. Write student information (name, ID, grade) to the file
 * 3. Read and display the file contents
 * 4. Append additional student data
 * 5. Display file statistics (size, permissions, modification time)
 *
 * Requirements:
 * - Use system calls (open, read, write, etc.) instead of stdio functions
 * - Handle all error conditions properly
 * - Clean up resources properly
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

// TODO: Implement the following functions

void create_and_write_file(const char *filename)
{
    // TODO: Create file and write initial student data
    // Use open() with appropriate flags
    // Write at least 3 student records
}

void read_and_display_file(const char *filename)
{
    // TODO: Read file contents and display them
    // Use open() and read() system calls
}

void append_student_data(const char *filename)
{
    // TODO: Append additional student data to the file
    // Use open() with O_APPEND flag
}

void display_file_stats(const char *filename)
{
    // TODO: Use stat() to get file information
    // Display: size, permissions, last modification time
}

int main()
{
    const char *filename = "student_data.txt";

    printf("File Operations Exercise\n");
    printf("========================\n\n");

    // TODO: Call the functions in the correct order
    // Don't forget error checking!

    return 0;
}

/*
 * Sample Output:
 * ==============
 * File Operations Exercise
 * ========================
 *
 * Creating file and writing student data...
 * File created successfully
 *
 * Reading file contents:
 * John Doe, ID: 12345, Grade: A
 * Jane Smith, ID: 23456, Grade: B+
 * Bob Johnson, ID: 34567, Grade: A-
 *
 * Appending additional data...
 * Data appended successfully
 *
 * Final file contents:
 * John Doe, ID: 12345, Grade: A
 * Jane Smith, ID: 23456, Grade: B+
 * Bob Johnson, ID: 34567, Grade: A-
 * Alice Wilson, ID: 45678, Grade: B
 *
 * File statistics:
 * Size: 156 bytes
 * Permissions: 644
 * Last modified: Mon Jan 07 10:30:25 2026
 */