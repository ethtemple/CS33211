#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "sharedResources.hpp"

std::array<int, TABLE_SIZE> table; 
int count = 0;

void* producer(void* arg) {
    int item = 0;

    while (true) {
        sleep(1);  // Simulate production time

        // Wait if there are no empty slots
        sem_wait(&empty);

        // Enter critical section
        pthread_mutex_lock(&mutex);
        table[count] = item;
        std::cout << "Producer produced item: " << item << std::endl;
        item++;
        count++;
        pthread_mutex_unlock(&mutex);  // Exit critical section

        // Signal that there is one more full slot
        sem_post(&full);
    }
}
