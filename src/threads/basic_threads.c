// Basic thread creation and management
// Compile with: gcc -pthread -o build/threads src/threads/basic_threads.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

// Thread function
void *thread_function(void *arg)
{
    int thread_id = *(int *)arg;

    printf("Thread %d: Starting\n", thread_id);

    // Simulate some work
    for (int i = 1; i <= 5; i++)
    {
        printf("Thread %d: Working... step %d\n", thread_id, i);
        sleep(1);
    }

    printf("Thread %d: Finished\n", thread_id);

    // Return value
    int *result = malloc(sizeof(int));
    *result = thread_id * 10;
    pthread_exit(result);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int *return_values[NUM_THREADS];

    printf("Creating %d threads...\n\n", NUM_THREADS);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i + 1;

        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0)
        {
            perror("pthread_create failed");
            exit(1);
        }
    }

    printf("All threads created. Main thread waiting...\n\n");

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++)
    {
        if (pthread_join(threads[i], (void **)&return_values[i]) != 0)
        {
            perror("pthread_join failed");
            exit(1);
        }

        printf("Thread %d joined with return value: %d\n",
               i + 1, *return_values[i]);
        free(return_values[i]);
    }

    printf("\nAll threads completed successfully!\n");

    return 0;
}