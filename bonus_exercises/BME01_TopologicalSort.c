// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define maxElems 11
// #define newLine printf("\n")

// // Queue Linked-List Implementation
// typedef struct qNode {
//     int data;
//     struct qNode *link;
// } qNode;

// typedef struct Queue {
//     qNode *front;
//     qNode *rear;
// } Queue;

// void initQueue(Queue *myQueue) {
//     myQueue -> front = NULL;
//     myQueue -> rear = NULL;
// }

// int isEmpty(Queue *myQueue) {
//     return (myQueue -> front == NULL);
// }

// void enqueue(Queue *myQueue, int x) {
//     qNode *alpha = (qNode *) malloc(sizeof(qNode));
//     alpha -> data = x;
//     alpha -> link = NULL;

//     if ((myQueue -> front) == NULL) {
//         myQueue -> front = alpha;
//         myQueue -> rear = alpha;
//     } else {
//         (myQueue -> rear) -> link = alpha;
//         myQueue -> rear = alpha;
//     }
// }

// int dequeue(Queue *myQueue) {
//     int x;

//     if ((myQueue -> front) == NULL) {
//         printf("Queue is empty.\n");
//         x = -1;
//     } else {
//         x = (myQueue -> front) -> data;
//         qNode *alpha = myQueue -> front;
//         myQueue -> front = (myQueue -> front) -> link;
//         free(alpha);
//     }

//     return x;
// }

// void printElems(Queue *myQueue) {
//     qNode *alpha = myQueue -> front;
//     while ((alpha -> link) != NULL) {
//         printf("%d ", alpha -> data);
//         alpha = alpha -> link;
//     }
//     printf("%d\n", alpha -> data);
// }
// // *Queue Linked-List Implementation

// typedef struct Node {
//     int succ;
//     struct Node *next;
// } Node;

// void printCount(int count[], int n) {
//     printf("[ Count List ]\n");
//     for (int i = 0; i <= n; i++) {
//         printf("%d | %d\n", i, count[i]);
//     }
//     newLine;
// }

// void printList(Node *list[], int n) {
//     printf("[ List of Nodes ]\n");
//     for (int i = 0; i <= n; i++) {
//         printf("%d | %p\n", i, list[i]);
//     }
// }

// void topologicalSort(int n) {
//     // Reference:
//     // https://pythontutor.com/c.html#code=typedef%20struct%20Node%20%7B%0A%20%20int%20data%3B%0A%20%20struct%20Node%20*link%3B%0A%7D%20Node%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20int%20*myArray%3B%0A%20%20%20%20myArray%20%3D%20%28int%20*%29%20malloc%20%2810%20*%20sizeof%28int%29%29%3B%0A%20%20%20%20%0A%20%20%20%20myArray%5B0%5D%20%3D%20-1%3B%0A%20%20%20%20myArray%5B2%5D%20%3D%2078%3B%0A%20%20%20%20%0A%20%0A%20%20%20%20%0A%20%20%20%20Node%20**nodesArray%3B%0A%20%20%20%20nodesArray%20%3D%20%28Node%20**%29%20malloc%20%2810%20*%20sizeof%28Node*%29%29%3B%0A%20%20%20%20%0A%20%20%20%20Node%20*a%3B%0A%20%20%20%20Node%20*b%20%3D%20%28Node%20*%29%20malloc%28sizeof%28Node%29%29%3B%0A%20%20%20%20Node%20*c%20%3D%20%28Node%20*%29%20malloc%28sizeof%28Node%29%29%3B%0A%20%20%20%20%0A%20%20%20%20nodesArray%5B0%5D%20%3D%20a%3B%0A%20%20%20%20%0A%20%20%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%2010%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20nodesArray%5Bi%5D%20%3D%20b%3B%0A%20%20%20%20%7D%0A%20%20%20%20%0A%20%20%20%20nodesArray%5B5%5D%20%3D%20c%3B%0A%20%20%20%20%0A%20%20%20%20Node%20*d%20%3D%20nodesArray%5B5%5D%3B%0A%20%20%20%20%0A%20%20%20%20free%28nodesArray%5B5%5D%29%3B%0A%20%20%20%20%0A%20%20%20%20free%28c%29%3B%0A%20%20%20%20free%28myArray%29%3B%0A%20%20%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%2010%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20free%28nodesArray%5Bi%5D%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20free%28nodesArray%29%3B%0A%0A%20%20return%200%3B%0A%7D&curInstr=32&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D
//     int *count;
//     count = (int *) malloc((n + 1) * sizeof(int));

//     // List of pointers for the SuccNext nodes.
//     Node **list;
//     list = (Node **) malloc((n + 1) * sizeof(Node *));

//     Queue myQueue;
//     initQueue(&myQueue);

//     // *Initializations
//     count[0] = -1;
//     list[0] = NULL;
//     for (int k = 1; k <= n; k++) {
//         count[k] = 0;
//         list[k] = NULL;
//     }

//     int m = n;  // [m] is the number of objects still to be outputted.
//     // *Initializations

//     // Read in data and generate count of direct predecessors and
//     // lists of direct successors.
//     // The pait 0, 0 terminated the input;
//     // *Read the data.
//     char data[][10] = {
//         "1 2",
//         "2 3",
//         "4 5",
//         "5 1",
//         "5 12",
//         "5 6",
//         "7 6",
//         "8 9",
//         "10 11",
//         "12 10",
//         "12 13",
//         "13 14",
//         "13 9",
//         "14 15",
//         "0 0"
//     };
//     char data1[][10] = {
//         "4 5",
//         "5 1",
//         "5 12",
//         "5 6",
//         "7 6",
//         "1 2",
//         "2 3",
//         "12 10",
//         "10 11",
//         "12 13",
//         "13 14",
//         "14 15",
//         "13 9",
//         "8, 9",
//         "0 0"
//     };

//     int i = 0;
//     // int j;
//     // int k;

//     while (data[i][0] != '0') {
//         // printf("%s, ", data[i]);

//         // Parse and convert line inputs to int.
//         char *temp = strtok(data[i], " ");
//         int j = atoi(temp);
//         temp = strtok(NULL, " ");
//         char *ptr;
//         printf("[%s]", temp);
//         // k = atoi(temp);
//         int k = atoi(temp);
//         // printf("%d, %d | ", j, k);
//         // newLine;

//         count[k] += 1;
//         Node *alpha = (Node *) malloc(sizeof(Node));
//         alpha -> succ = k;
//         alpha -> next = list[j];
//         list[j] = alpha;

//         i += 1;
//     }
//     // *Read the data.

//     // *Initialize output queque.
//     for (int k = 1; k <= n; k++) {
//         if (count[k] == 0) {
//             enqueue(&myQueue, k);
//         }
//     }
//     printElems(&myQueue);
//     newLine;
//     // *Initialize output queque.

//     // *Output objects.
//     Node *alpha = NULL;
//     int k2;

//     while (myQueue.front != NULL) {
//         printf("%d ", myQueue.front -> data);
//         m -= 1;
//         // printf("qqq%d\n", myQueue.front -> data);
//         alpha = list[myQueue.front -> data];

//         while (alpha != NULL) {
//             k2 = alpha -> succ;
//             count[k2] -= 1;

//             if (count[k2] == 0) {
//                 // printf("enqueue: %d\n", k2);
//                 enqueue(&myQueue, k2);
//             }
//             alpha = alpha -> next;
//         }

//         // myQueue.front = myQueue.front -> link;
//         dequeue(&myQueue);
//     }
//     // *Output objects.

//     // *Check for presence of loops;
//     if (m > 0) {
//         printf("Some objects comprise a loop.");
//         return;
//     }
//     // *Check for presence of loops;

//     printCount(count, n);
//     newLine;
//     printList(list, n);
    
//     // Free the manually allocated memories.
//     free(count);
//     for (int i = 0; i <= n; i++) {
//         free(list[i]);
//     }
//     free(list);
// }

// int main() {
//     int n = 15;

//     topologicalSort(n);

//     return 0;
// }

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

    while ((scanf("%d", &j) && scanf("%d", &k)) && (j != 0)) {
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