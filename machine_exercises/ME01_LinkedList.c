// #include <stdio.h>
// #include <stdlib.h>

// #define newLine printf("\n");

// typedef struct node Node;
// struct node {
//     int data;
//     Node* next;
// };

// void print_linked_list(Node*);
// void build_linked_list(Node**);
// void push(Node**, int);
// int count(Node*, int);
// int get_nth(Node*, int);
// void free_node(Node*);

// int main() {
//     // OJ sample inputs.
//     char input1[100] = "1 2 3 4 100 2 3 1 4 5 63 64 2 4 21 3 45 6 7 -1";
//     char input2[100] = "3 4 8 9 6 -1";

//     Node *head = NULL;
//     int index, nth;

//     // Build the Linked List.
//     build_linked_list(&head);

//     print_linked_list(head);

//     printf("\nget: %d\n", get_nth(head, 3));

//     printf("count: %d", count(head, 10));

//     printf("\nDONE");

//     // while (scanf(("%d", &index) > 0) && (index != -1)) {
//     //     nth = get_nth(head, index);
//     //     printf("%d %d %d\n", index, nth, count(head, nth));
//     // }

    
//     // Free the nodes (i.e., clear memory space).
//     free_node(head);

//     return 0;
// }

// void print_linked_list(Node *head) {
//     Node *current;
//     for (current = head; current != NULL; current = current -> next) {
//         printf("%d", current -> data);
//         newLine;
//     }
// }

// void build_linked_list(Node **head_ptr) {
//     int data;

//     // while (scanf(("%d", &data) > 0) && (data != -1)) {
//     //     Node *newNode = (Node*) malloc(sizeof(Node));

//     //     newNode -> data = data;
//     //     newNode -> next = *head_ptr;

//     //     *head_ptr = newNode;
//     // }

//     Node *newNode = (Node*) malloc(sizeof(Node));

//     newNode -> data = 1;
//     newNode -> next = *head_ptr;

//     *head_ptr = newNode;

//     Node *newNode1 = (Node*) malloc(sizeof(Node));

//     newNode1 -> data = 2;
//     newNode1 -> next = *head_ptr;

//     *head_ptr = newNode1;

//     Node *newNode2 = (Node*) malloc(sizeof(Node));

//     newNode2 -> data = 3;
//     newNode2 -> next = *head_ptr;

//     *head_ptr = newNode2;

//     Node *newNode3 = (Node*) malloc(sizeof(Node));

//     newNode3 -> data = 3;
//     newNode3 -> next = *head_ptr;

//     *head_ptr = newNode3;

// }

// int count(Node *head, int to_search) {
//     int n = 0;
//     Node* currentNode = head;

//     while (currentNode != NULL) {
//         if ((currentNode -> data) == to_search) n++;
//         currentNode = currentNode -> next;
//     }

//     return n;
// }

// int get_nth(Node *head, int index) {
//     Node* currentNode = head;
//     for (int i = 1; i < index; i++) currentNode = currentNode -> next;

//     return currentNode -> data;
// }

// void free_node(Node *a_node) {
//     if (a_node != NULL) {
//         free_node(a_node -> next);
//         free(a_node);
//     }
// }

#include <stdio.h>
#include <stdlib.h>

#define newLine printf("\n");

typedef struct node Node;
struct node {
    int data;
    Node* next;
};

void print_linked_list(Node*);
void build_linked_list(Node**);
int count(Node*, int);
int get_nth(Node*, int);
void free_node(Node*);

int main() {
    Node *head = NULL;
    int index, nth;

    // Build the Linked List.
    build_linked_list(&head);

    while ((scanf("%d", &index) > 0) && (index != -1)) {
        nth = get_nth(head, index);
        printf("%d %d %d\n", index, nth, count(head, nth));
    }

    // Free the nodes (i.e., clear memory space).
    free_node(head);

    return 0;
}

void print_linked_list(Node *head) {
    Node *current;
    for (current = head; current != NULL; current = current -> next) {
        printf("%d", current -> data);
        newLine;
    }
}

void build_linked_list(Node **head_ptr) {
    int data;

    while ((scanf("%d", &data) > 0) && (data != -1)) {
        Node *newNode = (Node*) malloc(sizeof(Node));

        newNode -> data = data;
        newNode -> next = *head_ptr;

        *head_ptr = newNode;
    }
}

int count(Node *head, int to_search) {
    int n = 0;
    Node* currentNode = head;

    while (currentNode != NULL) {
        if ((currentNode -> data) == to_search) n++;
        currentNode = currentNode -> next;
    }

    return n;
}

int get_nth(Node *head, int index) {
    Node* currentNode = head;
    
    for (int i = 1; i < index; i++) {
        if ((currentNode -> next) == NULL) return 0;
        currentNode = currentNode -> next;
    }

    return currentNode -> data;
}

void free_node(Node *a_node) {
    if (a_node != NULL) {
        free_node(a_node -> next);
        free(a_node);
    }
}
