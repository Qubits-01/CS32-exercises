#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define newLine printf("\n");

typedef struct Node {
    char data;
    struct Node *link;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void initStack(Stack *myStack) {
    myStack -> top = NULL;
}

bool isEmpty(Stack *myStack) {
    return (myStack -> top) == NULL;
}

void push(Stack *myStack, char x) {
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

char pop(Stack *myStack) {
    char popValue;

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
    // Stack myStack;
    // Stack *ptrMyStack = &myStack;
    // initStack(ptrMyStack);

    // push(ptrMyStack, 1);
    // push(ptrMyStack, 12);
    // push(ptrMyStack, 1);
    // push(ptrMyStack, 57);
    // pop(ptrMyStack);
    // pop(ptrMyStack);
    
    // printElems(ptrMyStack);

    Stack myStack;
    initStack(&myStack);
    char bTags[3][2] = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };
    char testCase[100000] = "f(a,b)-g[c]";
    int testCaseSize = strlen(testCase);
    int unemptyIndex = 0;  // For when the stack is not empty after the run.

    for (int i = 0; i < testCaseSize; i++) {
        // printf("%c ", testCase[i]);
        // newLine;

        // Check for closing tags when the stack is empty.
        if (isEmpty(&myStack)) {
            unemptyIndex = i;

            for (int j = 0; j < 3; j++) {
                if (testCase[i] == bTags[j][1]) {
                    printf("%d\n", i + 1);
                    exit(0);
                }
            }
        }

        // Check for opening tags.
        for (int j = 0; j < 3; j++) {
            if (testCase[i] == bTags[j][0]) {
                // printf("q%c \n", testCase[i]);
                push(&myStack, testCase[i]);
                break;
            }
        }

        // Check for closing tags.
        char popedTag;
        for (int j = 0; j < 3; j++) {
            if (testCase[i] == bTags[j][1]) {
                if (isEmpty(&myStack)) {
                    printf("%d\n", i + 1);
                    exit(0);
                } else {
                    popedTag = pop(&myStack);

                    if (popedTag != bTags[j][0]) {
                        printf("%d\n", i + 1);
                        exit(0);
                    } else {
                        break;
                    }
                }
            }
        }
    }

    if (!isEmpty(&myStack)) {
        printf("%d\n", unemptyIndex + 1);
    } else {
        printf("Success\n");
    }

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <string.h>

// typedef struct Node {
//     char data;
//     struct Node *link;
// } Node;

// typedef struct Stack {
//     Node *top;
// } Stack;

// void initStack(Stack *);
// bool isEmpty(Stack *);
// void push(Stack *, char);
// char pop(Stack *);

// int main() {
//     Stack myStack;
//     initStack(&myStack);
//     char bTags[3][2] = {
//         {'(', ')'},
//         {'[', ']'},
//         {'{', '}'}
//     };
//     char testCase[100000];
//     if (scanf("%s", testCase));
//     int testCaseSize = strlen(testCase);
//     int unemptyIndex = 0;  // For when the stack is not empty after the run.

//     for (int i = 0; i < testCaseSize; i++) {
//         // Check for closing tags when the stack is empty.
//         if (isEmpty(&myStack)) {
//             unemptyIndex = i;

//             for (int j = 0; j < 3; j++) {
//                 if (testCase[i] == bTags[j][1]) {
//                     printf("%d\n", i + 1);
//                     exit(0);
//                 }
//             }
//         }

//         // Check for opening tags.
//         for (int j = 0; j < 3; j++) {
//             if (testCase[i] == bTags[j][0]) {
//                 // printf("q%c \n", testCase[i]);
//                 push(&myStack, testCase[i]);
//                 break;
//             }
//         }

//         // Check for closing tags.
//         char popedTag;
//         for (int j = 0; j < 3; j++) {
//             if (testCase[i] == bTags[j][1]) {
//                 if (isEmpty(&myStack)) {
//                     printf("%d\n", i + 1);
//                     exit(0);
//                 } else {
//                     popedTag = pop(&myStack);

//                     if (popedTag != bTags[j][0]) {
//                         printf("%d\n", i + 1);
//                         exit(0);
//                     } else {break;}
//                 }
//             }
//         }
//     }

//     if (!isEmpty(&myStack)) {
//         printf("%d\n", unemptyIndex + 1);
//     } else {
//         printf("Success\n");
//     }

//     return 0;
// }

// void initStack(Stack *myStack) {
//     myStack -> top = NULL;
// }

// bool isEmpty(Stack *myStack) {
//     return (myStack -> top) == NULL;
// }

// void push(Stack *myStack, char x) {
//     Node *newNode = (Node *) malloc(sizeof(Node));
//     newNode -> data = x;
//     newNode -> link = NULL;

//     if (isEmpty(myStack)) {
//         myStack -> top = newNode;
//     } else {
//         newNode -> link = myStack -> top;
//         myStack -> top = newNode;
//     }
// }

// char pop(Stack *myStack) {
//     char popValue;

//     if (isEmpty(myStack)) {
//         printf("Stack is empty.\n");
//         popValue = -1;
//     } else {
//         Node *toPop = myStack -> top;
//         myStack -> top = toPop -> link;

//         popValue = toPop -> data;
//         free(toPop);
//     }

//     return popValue;
// }
