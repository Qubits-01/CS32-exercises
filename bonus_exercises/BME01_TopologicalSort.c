#include <stdio.h>
#include <stdlib.h>

#define maxElems 11
#define newLine printf("\n")

typedef struct Node {
    int succ;
    struct Node *next;
} Node;

void printCount(int count[]) {
    printf("[ Count List ]\n");
    for (int i = 0; i < maxElems; i++) {
        printf("%d | %d\n", i, count[i]);
    }
    newLine;
}

void printList(Node *list[]) {
    printf("[ List of Nodes ]\n");
    for (int i = 0; i < maxElems; i++) {
        printf("%d | %p\n", i, list[i]);
    }
}

void topologicalSort(int n) {
    int count[maxElems];
    Node *list[maxElems];

    // Initializations
    count[0] = -1;
    list[0] = NULL;
    for (int k = 1; k <= n; k++) {
        count[k] = 0;
        list[k] = NULL;
    }

    printCount(count);
    newLine;
    printList(list);
}

int main() {
    topologicalSort(10);

    return 0;
}
