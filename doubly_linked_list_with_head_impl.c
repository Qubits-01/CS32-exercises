// Doubly linked-list with head implementation.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define newLine printf("\n");

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedListWithHead {Node *head;} DLList;

// Core Functions
Node * getNewNode(int);
void initializeDLList(DLList *);
void insertAtFront(DLList *, int);
void insertAtTail(DLList *, int );
void deleteNode(Node *);
bool isEmpty(DLList *);

// Utility Functions
void freeDLList(Node *);  // Head node.
void freeNode(Node *node);
void printElems(DLList *);
void reversePrintElems(DLList *);
void underflow(void);
void overflow(void);

int main() {
    DLList dLList;
    initializeDLList(&dLList);

    printElems(&dLList);
    reversePrintElems(&dLList);
    // insertAtFront(&dLList, 12);
    // insertAtFront(&dLList, 45);
    // insertAtFront(&dLList, 15);

    insertAtTail(&dLList, 2);
    insertAtTail(&dLList, 2);
    insertAtTail(&dLList, 69);
    insertAtFront(&dLList, 15);

    printElems(&dLList);
    reversePrintElems(&dLList);

    return 0;
}

// CREATES A NEW [Node] WITH THE VALUE OF [x] APPLIED TO
// IT, AND RETURNS A POINTER TO THE SAID [Node].
Node * getNewNode(int x) {
    // Allocate memory for the [newNode].
    Node *newNode = (Node *) malloc(sizeof(struct Node));

    // Check [newNode] if there is an allocated memory.
    if (newNode == NULL) overflow();

    // Put the value of [x] in the [newNode] and set
    // [prev] and [next] pointers to [NULL].
    newNode -> data = x;
    newNode -> prev = NULL;
    newNode -> next = NULL;

    // Return a pointer of the [newNode].
    return newNode;
}

// INITIALIZE [DLList].
void initializeDLList(DLList *dLList) {
    dLList -> head = NULL;
}

void insertAtFront(DLList *dLList, int x) {
    Node *newNode = getNewNode(x);

    // When [DLList] is empty.
    if (isEmpty(dLList)) {
        dLList -> head = newNode;
        // printf("%d\n", dLList -> head -> data);
        return;
    }

    Node *head = dLList -> head;
    head -> prev = newNode;
    newNode -> next = head;
    // Remember that [head] only exists in this function scope,
    // that is why [dLLIst -> head] was used.
    dLList -> head = newNode;

    // printf("%p\n", dLList -> head -> next);
}

void insertAtTail(DLList *dLList, int x) {
    Node *newNode = getNewNode(x);

    // When [DLList] is empty.
    if (isEmpty(dLList)) {
        dLList -> head = newNode;
        return;
    }

    // When [DLList] is not empty.
    Node *nodeIterator = dLList -> head;

    // Traverse all the [Node]s from left to right until the last [Node].
    while (nodeIterator -> next != NULL) nodeIterator = nodeIterator -> next;
    nodeIterator -> next = newNode;
    newNode -> prev = nodeIterator;
}

void deleteNode(Node * node) {
    if (node == NULL) {
        printf("Node does not exist.\n");
        exit(1);
    }

    (node -> prev) -> next = node -> next;
    (node -> next) -> prev = node -> prev;

    freeNode(node);
}

bool isEmpty(DLList *dLList) {
    if (dLList -> head == NULL) {
        return true;
    } else {
        return false;
    }
}

void freeDLList(Node *head) {
    if (head != NULL) {
        freeDLList(head -> next);
        free(head);
    }
}

void freeNode(Node * node) {
    if (node != NULL) free(node);
}

void printElems(DLList *dLList) {
    // Check if [dLList] is empty or [NULL].
    if (isEmpty(dLList)) {
        printf("[ List is empty. ]\n");
        return;
    };

    Node *nodeIterator = dLList -> head;
    while (nodeIterator -> next != NULL) {
        printf("%d ", nodeIterator -> data);
        nodeIterator = nodeIterator -> next;
    }
    printf("%d ", nodeIterator -> data);  // Print the last [Node].

    newLine;
}

void reversePrintElems(DLList *dLList) {
    // Check if [dLList] is empty or [NULL].
    if (isEmpty(dLList)) {
        printf("[ List is empty. ]\n");
        return;
    }

    Node *nodeIterator = dLList -> head;
    // Go to the last [Node] of [dLList].
    while (nodeIterator -> next != NULL) {
        nodeIterator = nodeIterator -> next;
    }

    // Traverse [dLList] starting from the last [Node].
    while (nodeIterator -> prev != NULL) {
        printf("%d ", nodeIterator -> data);
        nodeIterator = nodeIterator -> prev;
    }
    printf("%d ", nodeIterator -> data);

    newLine;
}

void underflow(void) {
    printf("[ UNDERFLOW ]");
    newLine;
    exit(1);
}

void overflow(void) {
    printf("[ OVERFLOW ]");
    newLine;
    exit(1);
}

