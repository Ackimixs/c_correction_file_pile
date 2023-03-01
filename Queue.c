#include "Queue.h"

struct Queue* createEmptyQueue() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->array = (int*) malloc(sizeof(int) * QUEUE_SIZE);
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

void enqueue(struct Queue* queue, int val, bool* valid) {
    if (queue->size == QUEUE_SIZE) {
        *valid = false;
        return;
    }
    queue->array[queue->tail] = val;
    queue->tail = (queue->tail + 1) % QUEUE_SIZE;
    queue->size++;
    *valid = true;
}

int head(struct Queue* queue, bool* valid) {
    if (queue->size == 0) {
        *valid = false;
        return 0;
    }
    *valid = true;
    return queue->array[queue->head];
}

int dequeue(struct Queue* queue, bool* valid) {
    if (queue->size == 0) {
        *valid = false;
        return 0;
    }
    int val = queue->array[queue->head];
    queue->head = (queue->head + 1) % QUEUE_SIZE;
    queue->size--;
    *valid = true;
    return val;
}

unsigned int queueSize(struct Queue* queue) {
    return queue->size;
}

bool isQueueEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void printQueue(struct Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    int i = queue->head;
    while (i != queue->tail) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("\n");
}

void deleteQueue(struct Queue** queue) {
    free((*queue)->array);
    free(*queue);
    *queue = NULL;
}
