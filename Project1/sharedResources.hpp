#ifndef SHARED_RESOURCES_HPP
#define SHARED_RESOURCES_HPP

#include <array>
#include <semaphore.h>
#include <pthread.h>

#define TABLE_SIZE 2

extern std::array<int, TABLE_SIZE> table;
extern int count;            // tracks the current position in the table
extern sem_t empty;          // count empty slots
extern sem_t full;           // count filled slots
extern pthread_mutex_t mutex; // mutex for protecting critical section

#endif
