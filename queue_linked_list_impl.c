#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *myQueue) {
    myQueue -> front = NULL;
    myQueue -> rear = NULL;
}

int isEmpty(Queue *myQueue) {
    return (myQueue -> front == NULL);
}

void enqueue(Queue *myQueue, int x) {
    Node *alpha = (Node *) malloc(sizeof(Node));
    alpha -> data = x;
    alpha -> link = NULL;

    if ((myQueue -> front) == NULL) {
        myQueue -> front = alpha;
        myQueue -> rear = alpha;
    } else {
        (myQueue -> rear) -> link = alpha;
        myQueue -> rear = alpha;
    }
}

int dequeue(Queue *myQueue) {
    int x;

    if ((myQueue -> front) == NULL) {
        printf("Queue is empty.\n");
        x = -1;
    } else {
        x = (myQueue -> front) -> data;
        Node *alpha = myQueue -> front;
        myQueue -> front = (myQueue -> front) -> link;
        free(alpha);
    }

    return x;
}

void printElems(Queue *myQueue) {
    Node *alpha = myQueue -> front;
    while ((alpha -> link) != NULL) {
        printf("%d ", alpha -> data);
        alpha = alpha -> link;
    }
    printf("%d\n", alpha -> data);
}

int main() {
    Queue myQueue;
    initQueue(&myQueue);

    printf("%d\n", isEmpty(&myQueue));
    printf("dequeue: %d\n", dequeue(&myQueue));

    enqueue(&myQueue, 2);
    enqueue(&myQueue, 8);
    printElems(&myQueue);

    enqueue(&myQueue, 0);
    enqueue(&myQueue, 8);
    printElems(&myQueue);

    printf("dequeue: %d\n", dequeue(&myQueue));
    printElems(&myQueue);

    return 0;
}
