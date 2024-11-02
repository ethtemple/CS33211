# Producer-Consumer Problem

The project is to solve the Producer-Consumer problem where the producer puts items on the table and the consumer takes them off.

## Features

- **Producer-Consumer Synchronization**: The producer must wait when the table is full and the consumer when it is empty.
- **Protects Critical Section**: Utilizes semaphores and mutexes to manage concurrent access to shared resources.

## Note

This project involved a lot of learning and failing. ChatGPT was utilized to help figure out the concepts and assisted in 
program design however all code is my own. I used Kahnmigo Code Tutor through ChatGPT which is designed to give hints and helpful advice
while still allowing the user (in this case me) to write the code for themself. It is a very useful tool and helped me understand
Semaphores, Mutex locks, and Threads and how they are used in code much better than just googling it did.

## Files

- `main.cpp`: Contains the main function that initializes semaphores and creates producer and consumer threads.
- `producer.cpp`: Implements the producer to place items on the table.
- `consumer.cpp`: Implements the consumer to take items off the table.
- `sharedResources.hpp`: Declares shared variables, semaphores, and mutexes used by both the producer and consumer.

## Compilation

To compile the project, use the following command:

```bash
g++ main.cpp producer.cpp consumer.cpp -lpthread -o producer_consumer
