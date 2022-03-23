#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *link;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void initStack(Stack *myStack) {
    myStack -> top = NULL;
}

bool isEmpty(Stack *myStack) {
    if ((myStack -> top) == NULL) {
        return true;
    } else {
        return false;
    }
}

void push(Stack *myStack, int x) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode -> data = x;
    newNode -> link = NULL;

    if (isEmpty(myStack)) {
        myStack -> top = newNode;
    } else {
        newNode -> link = myStack -> top;
        myStack -> top = newNode;
    }
}

int pop(Stack *myStack) {
    int popValue;

    if (isEmpty(myStack)) {
        printf("Stack is empty.\n");
        popValue = -1;
    } else {
        Node *toPop = myStack -> top;
        myStack -> top = toPop -> link;

        popValue = toPop -> data;
        free(toPop);
    }

    return popValue;
}

void printElems(Stack *myStack) {
    if (isEmpty(myStack)) {
        printf("Stack is empty.\n");
    } else {
        Node *alpha = myStack -> top;

        while ((alpha -> link) != NULL) {
            printf("%d ", alpha -> data);
            alpha = alpha -> link;
        }
        printf("%d\n", alpha -> data);
    }
}

int main() {
    Stack myStack;
    Stack *ptrMyStack = &myStack;
    initStack(ptrMyStack);

    push(ptrMyStack, 1);
    push(ptrMyStack, 12);
    push(ptrMyStack, 1);
    push(ptrMyStack, 57);
    pop(ptrMyStack);
    pop(ptrMyStack);
    
    printElems(ptrMyStack);

    return 0;
}
