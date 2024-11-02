#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "sharedResources.hpp"

void* consumer(void* arg) {
    while (true) {
        sleep(2);  // Simulate consumption time

        // Wait if there are no full slots
        sem_wait(&full);

        // Enter critical section
        pthread_mutex_lock(&mutex);
        int item = table[count - 1];
        std::cout << "Consumer consumed item: " << item << std::endl;
        count--;
        pthread_mutex_unlock(&mutex);  // Exit critical section

        // Signal that there is one more empty slot
        sem_post(&empty);
    }
}
