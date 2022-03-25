#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define newLine printf("\n")

// Reference:
// https://pythontutor.com/c.html#code=typedef%20struct%20Node%20%7B%0A%20%20char%20*key%3B%0A%20%20char%20*data%3B%0A%20%20struct%20Node*%20link%3B%0A%7D%20Node%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20Node%20*a%20%3D%20%28Node%20*%29%20malloc%28sizeof%28Node%29%29%3B%0A%20%20%0A%20%20a%20-%3E%20key%20%3D%20%22KEYS%22%3B%0A%0A%20%20return%200%3B%0A%7D&curInstr=3&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D
typedef struct Node {
    char *key;
    // char *data;  // Not needed in this context.
    struct Node* link;
} Node;

typedef struct Stack {
    Node * top;
} Stack;

typedef struct HashTable {
    Stack **table;
} HashTable;

void initStack(Stack *myStack) {
    myStack -> top = NULL;
}

void initHashTable(HashTable *myHashTable) {
    myHashTable -> table = NULL;
}

void push(Stack *myStack, char key[]) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode -> key = key;
    // newNode -> data = data;  // Not needed in this context.
    newNode -> link = NULL;

    if ((myStack -> top) == NULL) {
        myStack -> top = newNode;
    } else {
        newNode -> link = myStack -> top;
        myStack -> top = newNode;
    }
}

long long int strToInt(char input[]) {
    // printf("[%s]\n", input);
    long long int output;
    int len = strlen(input) - 1;
    int i = 0;
    long long int temp = 0;

    while (input[i] != '\0') {
        temp = input[i] * pow(256, len - i);
        printf("(%lld)\n", temp);
        output += temp;
        i += 1;
    }

    return output;
}

int hashFunction(int type, int k) {
    if (type == 1) {
        return (k % 32);
    } else if (type == 2) {
        int a = pow(2, 11);
        return ((31 * k) % a) >> (11 - 5);
    } else if (type == 3) {
        return ((1731 * k + 520123) % 524287) % 32;
    }

    return -1;
}

int hashFunction1(int k) {
    return (k % 32);
}

int hashFunction2(int k) {
    int a = pow(2, 11);
    return ((31 * k) % a) >> (11 - 5);
}

int hashFunction3(int k) {
    return ((1731 * k + 520123) % 524287) % 32;
}

void displayHTable(HashTable *myHashTable) {
    char *contents;
    for (int i = 0; i < 32; i++) {
        if ((myHashTable -> table)[i] == NULL) {
            contents = "NULL";
        }

        printf("%d: %s\n", i, contents);
    }
};

void freeHTable(HashTable *myHashTable) {
    for (int i = 0; i < 32; i++) free((myHashTable -> table)[i]);
    free(myHashTable);
}

int main() {
    int type = 1;
    int nKeys = 9;
    char keys[][15] = {
        "KEYS",
        "compromise",
        "accountant",
        "presidency",
        "photograph",
        "temptation",
        "brilliance",
        "censorship",
        "possession",
        "federation"
    };

    // Initialize
    HashTable myHashTable;
    initHashTable(&myHashTable);

    Stack **heads;
    heads = (Stack **) malloc(32 * sizeof(Stack *));
    for (int i = 0; i < 32; i++) heads[i] = NULL;

    myHashTable.table = heads;


    for (int i = 0; i < nKeys; i++) {
        // *chainedHashTableInsert
        long long int index = hashFunction(type, strToInt(keys[i]));
        printf("key: %s | int: %lld | index: %lld\n", keys[i], strToInt(keys[i]), index);
        // *chainedHashTableInsert
    }

    displayHTable(&myHashTable);
    freeHTable(&myHashTable);

    return 0;
}
