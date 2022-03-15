#include <stdio.h>
#include <stdlib.h>

typedef char StackElemType;
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
    // Stack stack;
    // StackElemType x;
    // char brackets[7] = {'[', ']', '{', '}', '(', ')', '\0'};

    // initStack(&stack);
    // char testcase1[20] = "{[]}({]";
    // printf("%s\n", testcase1);

    // int i = 0;
    // int first_opening = 1;
    // int isEnd = 0;

    // while (i < strlen(testcase1)) {
    //     // printf("%c %d\n", testcase1[i], i);
    //     if (isEnd == 1) break;

    //     int j = 0;
    //     while (brackets[j] != '\0') {
    //         // printf("%c", closings[j]);
    //         if (testcase1[i] == brackets[j]) {
    //             // printf("w %c\n", brackets[j]);
    //             break;
    //         }

    //         j++;
    //     }

    //     if (j == 6) {
    //         i++;
    //         continue;
    //     }

    //     if (j % 2 != 0) {
    //         if (isEmptyStack(&stack)) {
    //             printf("%d\n", i + 1);
    //             isEnd = 1;
    //             break;
    //         }

    //         pop(&stack, &x);

    //         if (isEmptyStack(&stack)) {
    //             first_opening = i + 2;
    //         }

    //         if (x != brackets[j - 1]) {
    //             printf("%d\n", i + 1);
    //             isEnd = 1;
    //             break;
    //         }
    //     } else {
    //         push(&stack, testcase1[i]);
    //     }
    //     i++;
    // }

    // if (isEnd != 1) {
    //     if (isEmptyStack(&stack)) {
    //         printf("Success\n");
    //     } else {
    //         printf("%d\n", first_opening);
    //     }
    // }

    // return 0;

    Stack stack;
    StackElemType x;
    char brackets[7] = {'[', ']', '{', '}', '(', ')', '\0'};

    initStack(&stack);
    char testcase1[100001];

    while (scanf("%s", testcase1) && (testcase1[0] != '\0') {
        int i = 0;
        int first_opening = 1;
        int isEnd = 0;

        while (i < strlen(testcase1)) {
            if (isEnd == 1) break;

            int j = 0;
            while (brackets[j] != '\0') {
                if (testcase1[i] == brackets[j]) break;
                j++;
            }

            if (j == 6) {
                i++;
                continue;
            }

            if (j % 2 != 0) {
                if (isEmptyStack(&stack)) {
                    printf("%d\n", i + 1);
                    isEnd = 1;
                    break;
                }

                pop(&stack, &x);

                if (isEmptyStack(&stack)) {
                    first_opening = i + 2;
                }

                if (x != brackets[j - 1]) {
                    printf("%d\n", i + 1);
                    isEnd = 1;
                    break;
                }
            } else {
                push(&stack, testcase1[i]);
            }
            i++;
        }

        if (isEnd != 1) {
            if (isEmptyStack(&stack)) {
                printf("Success\n");
            } else {
                printf("%d\n", first_opening);
            }
        }
    }
    
    return 0;
}
