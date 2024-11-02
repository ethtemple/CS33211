#include <pthread.h>
#include <semaphore.h>
#include "sharedResources.hpp"

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void* producer(void*);
void* consumer(void*);

int main() {
    pthread_t prodThread, consThread;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, TABLE_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, nullptr);

    // Create producer and consumer threads
    pthread_create(&prodThread, nullptr, producer, nullptr);
    pthread_create(&consThread, nullptr, consumer, nullptr);

    // Wait for threads to complete
    pthread_join(prodThread, nullptr);
    pthread_join(consThread, nullptr);

    // Clean up
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
