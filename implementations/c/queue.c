// ! Queue

#include <stdio.h>

struct Queue
{
    int head;
    int tail;
    int size;
    int *array;
};

int main() {
    struct Queue queue;
    queue.size = 5;
    queue.head = 0;
    queue.tail = 0;
    queue.array = (int *)malloc(queue.size * sizeof(int));

    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    printf("Head: %d\n", queue.head);
    printf("Tail: %d\n", queue.tail);
    for (int i = 0; i < queue.size; i++) {
        printf("%d\n", queue.array[i]);
    }

    printf("Dequeue: %d\n", Dequeue(&queue));
    printf("Head: %d\n", queue.head);
    printf("Tail: %d\n", queue.tail);
}

void Enqueue(struct Queue *queue, int number) {
    queue->array[queue->tail] = number;
    if (queue->tail == queue->size) {
        queue->tail = -1;
    } else {
        queue->tail += 1;
    }
}

int Dequeue(struct Queue *queue) {
    int value = queue->array[queue->head];
    if (queue->head == queue->size) {
        queue->head = 1;
    } else {
        queue->head += 1;
    }

    return value;
}