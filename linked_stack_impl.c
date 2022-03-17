#include <stdio.h>
#include <stdlib.h>

typedef int StackElemType;
typedef struct stacknode StackNode;

struct stacknode {
    StackElemType info;
    StackNode *link;
};

typedef struct stack Stack;
struct stack {
    StackNode *top;
};

void initStack(Stack *stack) {
    stack -> top = NULL;
}

int isEmptyStack(Stack *stack) {
    return (stack -> top == NULL);
}

void stackOverflow(void) {
    printf("Stack overflow detected.\n");
    exit(1);
}

void stackUnderflow(void) {
    printf("Stack underflow detected.\n");
    exit(1);
}

void push(Stack *stack, StackElemType x) {
    StackNode *alpha;
    alpha = (StackNode *) malloc(sizeof(StackNode));

    if (alpha == NULL) {
        stackOverflow();
    } else {
        alpha -> info = x;
        alpha -> link = stack -> top;
        stack -> top = alpha;
    }
}

void pop(Stack *stack, StackElemType *x) {
    if (stack -> top == NULL) {
        stackUnderflow();
    } else {
        StackNode *alpha;
        alpha = stack -> top;
        *x = alpha -> info;
        stack -> top = alpha -> link;
        free(alpha);
    }
}

int main(void) {
    // Example procedure that uses a stack.
    Stack stack;
    StackElemType x;

    initStack(&stack);
    for (int i = 1; i <= 5; i++) {
        push(&stack, 100 * i);
    }

    while(!isEmptyStack(&stack)) {
        pop(&stack, &x);
        printf("%d\n", x);
    }

    return 0;
}
