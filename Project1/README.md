# Producer-Consumer Problem

The project is to solve the Producer-Consumer problem where the producer puts items on the table and the consumer takes them off.

## Features

- **Producer-Consumer Synchronization**: The producer must wait when the table is full and the consumer when it is empty.
- **Protects Critical Section**: Utilizes semaphores and mutexes to manage concurrent access to shared resources.

## Files

- `main.cpp`: Contains the main function that initializes semaphores and creates producer and consumer threads.
- `producer.cpp`: Implements the producer to place items on the table.
- `consumer.cpp`: Implements the consumer to take items off the table.
- `sharedResources.hpp`: Declares shared variables, semaphores, and mutexes used by both the producer and consumer.

## Compilation

To compile the project, use the following command:

```bash
g++ main.cpp producer.cpp consumer.cpp -lpthread -o producer_consumer
