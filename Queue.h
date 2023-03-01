#ifndef C_CORRECTION_QUEUE_H
#define C_CORRECTION_QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

struct Queue {
    int* array;
    unsigned int size;
    int head;
    int tail;
};

struct Queue* createEmptyQueue();

void enqueue(struct Queue* queue, int val, bool* valid);

int head(struct Queue* queue, bool* valid);

int dequeue(struct Queue* queue, bool* valid);

unsigned int queueSize(struct Queue* queue);

bool isQueueEmpty(struct Queue* queue);

void printQueue(struct Queue* queue);

void deleteQueue(struct Queue** queue);

#endif //C_CORRECTION_QUEUE_H
