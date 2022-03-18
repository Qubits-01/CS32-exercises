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

typedef struct DoublyLinkedListWithHead {Node *head} DLList;

// Core Functions
Node * getNewNode(int x);
void initializeDLList(DLList *dLList);
void insertAtFront(DLList *dLList, int x);
void insertAtTail(DLList *dLList, int x);
void isEmpty(DLList *dLList);

// Utility Functions
void printElems(DLList *dLList);
void reversePrintElems(DLList *dLList);
void underflow(void);
void overflow(void);

int main() {

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

// INITIALIZE [DLList] WITH [NULL] SET TO ITS PROPERTIES.
void initializeDLList(DLList *dLList) {
    // [Head] pointer's [data], [prev], and [next]
    // properties are set to [NULL].
    Node *newNode = getNewNode(NULL);
    dLList -> head = newNode;
}

void insertAtFront(DLList *dLList, int x) {
    Node *head = dLList -> head;

    // When [DLList] is empty (only the [head] node is present).
    if (head -> data == NULL) {
        head -> data = x;
        return;
    }

    // When [DLList] is not empty.
    Node *newNode = getNewNode(x);
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(DLList *dLList, int x) {
    Node *head = dLList -> head;

    // When [DLList] is empty (only the [head] node is present).
    if (head -> data == NULL) {
        head -> data = x;
        return;
    }

    // When [DLList] is not empty.
    Node *nodeIterator = head;
    Node *newNode = getNewNode(x);

    // Traverse all the [Node]s from left to right until the last [Node].
    while (nodeIterator -> next != NULL) nodeIterator = nodeIterator -> next;
    nodeIterator -> next = newNode;
    newNode -> prev = nodeIterator;
}

void isEmpty(DLList *dLList) {
    // The value of the [data] property of [head] indicates
    // whether [dLList] is empty or not. That is, [dLLIst] is
    // empty when the [head] [data] property is [NULL].
    Node *head = dLList -> head;
    if (head -> data == NULL) {
        return true;
    } else {
        return false;
    }
}

void printElems(DLList *dLList) {
    Node *head = dLList -> head;
    Node *nodeIterator = head;

    // Check if [dLList] is empty or [NULL]. That is,
    // only the [head] node is present in the said [dLList].
    if (isEmpty(dLList)) printf("[ List is empty. ]");

    while (nodeIterator -> next != NULL) {
        printf("%d ", nodeIterator -> data);
        nodeIterator = nodeIterator -> next;
    }

    newLine;
}

void reversePrintElems(DLList *dLList) {
    Node *head = dLList -> head;
    Node *nodeIterator = head;

    // Check if [dLList] is empty or [NULL]. That is,
    // only the [head] node is present in the said [dLList].
    if (head -> data == NULL) printf("[ List is empty. ]");

    while (nodeIterator -> next != NULL) {
        printf("%d ", nodeIterator -> data);
        nodeIterator = nodeIterator -> next;
    }

    newLine;
}

void underflow(void) {
    printf("[ UNDERFLOW ]");
    exit(1);
}

void overflow(void) {
    printf("[ OVERFLOW ]");
    exit(1);
}

