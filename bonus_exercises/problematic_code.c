#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue Linked-List Implementation
typedef struct qNode {
    int data;
    struct qNode *link;
} qNode;

typedef struct Queue {
    qNode *front;
    qNode *rear;
} Queue;

void initQueue(Queue *myQueue) {
    myQueue -> front = NULL;
    myQueue -> rear = NULL;
}

int isEmpty(Queue *myQueue) {
    return (myQueue -> front == NULL);
}

void enqueue(Queue *myQueue, int x) {
    qNode *alpha = (qNode *) malloc(sizeof(qNode));
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
        qNode *alpha = myQueue -> front;
        myQueue -> front = (myQueue -> front) -> link;
        free(alpha);
    }

    return x;
}
// *Queue Linked-List Implementation

typedef struct Node {
    int succ;
    struct Node *next;
} Node;

void topologicalSort(int n) {
    int *count;
    count = (int *) malloc((n + 1) * sizeof(int));

    // List of pointers for the SuccNext nodes.
    Node **list;
    list = (Node **) malloc((n + 1) * sizeof(Node *));

    Queue myQueue;
    initQueue(&myQueue);

    // *Initializations
    count[0] = -1;
    list[0] = NULL;
    for (int k = 1; k <= n; k++) {
        count[k] = 0;
        list[k] = NULL;
    }

    int m = n;  // [m] is the number of objects still to be outputted.
    // *Initializations

    // Read in data and generate count of direct predecessors and
    // lists of direct successors.
    // The pait 0, 0 terminated the input;
    // *Read the data.
    int j;
    int k;
    char data[20];

    while ((fgets(data, 20, stdin)) && (data[0] != '0')) {
        // Parse and convert line inputs to int.
        char *temp = strtok(data, " ");
        j = atoi(temp);
        temp = strtok(NULL, " ");
        k = atoi(temp);

        count[k] += 1;
        Node *alpha = (Node *) malloc(sizeof(Node));
        alpha -> succ = k;
        alpha -> next = list[j];
        list[j] = alpha;
    }
    // *Read the data.

    // *Initialize output queque.
    for (int k = 1; k <= n; k++) {
        if (count[k] == 0) {
            enqueue(&myQueue, k);
        }
    }
    // *Initialize output queque.

    // *Output objects.
    Node *alpha = NULL;
    int k2;

    while (myQueue.front != NULL) {
        printf("%d ", myQueue.front -> data);
        m -= 1;
        // printf("qqq%d\n", myQueue.front -> data);
        alpha = list[myQueue.front -> data];

        while (alpha != NULL) {
            k2 = alpha -> succ;
            count[k2] -= 1;

            if (count[k2] == 0) {
                // printf("enqueue: %d\n", k2);
                enqueue(&myQueue, k2);
            }
            alpha = alpha -> next;
        }

        // myQueue.front = myQueue.front -> link;
        dequeue(&myQueue);
    }
    // *Output objects.

    // *Check for presence of loops;
    if (m > 0) {
        printf("Some objects comprise a loop.");
        return;
    }
    // *Check for presence of loops;
    
    // Free the manually allocated memories.
    free(count);
    for (int i = 0; i <= n; i++) {
        free(list[i]);
    }
    free(list);
}

int main() {
    int n;
    if (scanf("%d", &n)) {};

    topologicalSort(n);

    return 0;
}
