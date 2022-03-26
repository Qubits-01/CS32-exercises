// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>

// #define newLine printf("\n")

// // Reference:
// // https://pythontutor.com/c.html#code=typedef%20struct%20Node%20%7B%0A%20%20char%20*key%3B%0A%20%20char%20*data%3B%0A%20%20struct%20Node*%20link%3B%0A%7D%20Node%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20Node%20*a%20%3D%20%28Node%20*%29%20malloc%28sizeof%28Node%29%29%3B%0A%20%20%0A%20%20a%20-%3E%20key%20%3D%20%22KEYS%22%3B%0A%0A%20%20return%200%3B%0A%7D&curInstr=3&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D
// typedef struct Node {
//     int key;
//     char *data;
//     struct Node* link;
// } Node;

// typedef struct Stack {
//     Node * top;
// } Stack;

// typedef struct HashTable {
//     Stack **table;
// } HashTable;

// void initStack(Stack *myStack) {
//     myStack -> top = NULL;
// }

// void initHashTable(HashTable *myHashTable) {
//     myHashTable -> table = NULL;
// }

// void push(Stack *myStack, int key, char *data) {
//     Node *newNode = (Node *) malloc(sizeof(Node));
//     newNode -> key = key;
//     newNode -> data = data;
//     newNode -> link = NULL;

//     if ((myStack -> top) == NULL) {
//         myStack -> top = newNode;
//     } else {
//         newNode -> link = myStack -> top;
//         myStack -> top = newNode;
//     }
// }

// int hashFunction(int type, int k) {
//     if (type == 1) {
//         return (k % 32);
//     } else if (type == 2) {
//         int a = pow(2, 11);
//         return ((31 * k) % a) >> (11 - 5);
//     } else if (type == 3) {
//         return ((1731 * k + 520123) % 524287) % 32;
//     }

//     return -1;
// }

// void displayHTable(HashTable *myHashTable) {
//     for (int i = 0; i < 32; i++) {
//         Stack *myStack = (myHashTable -> table)[i];
//         Node *alpha = myStack -> top;

//         printf("%d: ", i);
//         while (alpha != NULL) {
//             printf("%s ", alpha -> data);
//             alpha = alpha -> link;
//         }
//         newLine;
//     }
// };

// // Reference:
// // https://pythontutor.com/c.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstring.h%3E%0A%23include%20%3Cmath.h%3E%0A%0A%23define%20newLine%20printf%28%22%5Cn%22%29%0A%0A//%20Reference%3A%0A//%20https%3A//pythontutor.com/c.html%23code%3Dtypedef%2520struct%2520Node%2520%257B%250A%2520%2520char%2520*key%253B%250A%2520%2520char%2520*data%253B%250A%2520%2520struct%2520Node*%2520link%253B%250A%257D%2520Node%253B%250A%250Aint%2520main%2528%2529%2520%257B%250A%2520%2520Node%2520*a%2520%253D%2520%2528Node%2520*%2529%2520malloc%2528sizeof%2528Node%2529%2529%253B%250A%2520%2520%250A%2520%2520a%2520-%253E%2520key%2520%253D%2520%2522KEYS%2522%253B%250A%250A%2520%2520return%25200%253B%250A%257D%26curInstr%3D3%26mode%3Ddisplay%26origin%3Dopt-frontend.js%26py%3Dc_gcc9.3.0%26rawInputLstJSON%3D%255B%255D%0Atypedef%20struct%20Node%20%7B%0A%20%20%20%20char%20*key%3B%0A%20%20%20%20//%20char%20*data%3B%20%20//%20Not%20needed%20in%20this%20context.%0A%20%20%20%20struct%20Node*%20link%3B%0A%7D%20Node%3B%0A%0Atypedef%20struct%20Stack%20%7B%0A%20%20%20%20Node%20*%20top%3B%0A%7D%20Stack%3B%0A%0Avoid%20initStack%28Stack%20*myStack%29%20%7B%0A%20%20%20%20myStack%20-%3E%20top%20%3D%20NULL%3B%0A%7D%0A%0Avoid%20push%28Stack%20*myStack,%20char%20key%5B%5D%29%20%7B%0A%20%20%20%20Node%20*newNode%20%3D%20%28Node%20*%29%20malloc%28sizeof%28Node%29%29%3B%0A%20%20%20%20newNode%20-%3E%20key%20%3D%20key%3B%0A%20%20%20%20//%20newNode%20-%3E%20data%20%3D%20data%3B%20%20//%20Not%20needed%20in%20this%20context.%0A%20%20%20%20newNode%20-%3E%20link%20%3D%20NULL%3B%0A%0A%20%20%20%20if%20%28%28myStack%20-%3E%20top%29%20%3D%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20myStack%20-%3E%20top%20%3D%20newNode%3B%0A%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20newNode%20-%3E%20link%20%3D%20myStack%20-%3E%20top%3B%0A%20%20%20%20%20%20%20%20myStack%20-%3E%20top%20%3D%20newNode%3B%0A%20%20%20%20%7D%0A%7D%0A%0Avoid%20freeStack%28Stack%20*myStack%29%20%7B%0A%20%20%20%20if%20%28%28myStack%20-%3E%20top%29%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20Node%20*alpha%20%3D%20myStack%20-%3E%20top%3B%0A%20%20%20%20%20%20%20%20Node%20*beta%20%3D%20NULL%3B%0A%0A%20%20%20%20%20%20%20%20while%20%28alpha%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20beta%20%3D%20alpha%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20alpha%20%3D%20alpha%20-%3E%20link%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20free%28beta%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20Stack%20myStack%3B%0A%20%20initStack%28%26myStack%29%3B%0A%20%20%0A%20%20push%28%26myStack,%20%22qw%22%29%3B%0A%20%20push%28%26myStack,%20%2213de%22%29%3B%0A%20%20push%28%26myStack,%20%2232%22%29%3B%0A%20%20%0A%20%20freeStack%28%26myStack%29%3B%0A%20%20%0A%20%20return%200%3B%20%20%0A%7D&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D
// void freeStack(Stack *myStack) {
//     if ((myStack -> top) != NULL) {
//         Node *alpha = myStack -> top;
//         Node *beta = NULL;

//         while (alpha != NULL) {
//             beta = alpha;
//             alpha = alpha -> link;
//             free(beta);
//         }
//     }

//     free(myStack);
// }

// void freeHTable(HashTable *myHashTable) {
//     for (int i = 0; i < 32; i++) {
//         Stack *myStack = (myHashTable -> table)[i];
//         freeStack(myStack);
//     };
// }

// void chainedHashTableInsert(HashTable *myHashTable, int key, char *data, int type) {
//     // **Search for possible duplicate key.
//     int index = hashFunction(type, key);
//     Stack *myStack = (myHashTable -> table)[index];
//     Node *alpha = myStack -> top;
//     printf("inputStr: %s | key: %d | index: %d\n", data, key, index);

//     while (alpha != NULL) {
//         int isDataEqual = strcmp(alpha -> data, data);  // Returns 0 when strings are equal.
//         if ((alpha -> key == key) && (isDataEqual == 0)) {
//             printf("Duplicate key found: %s\n", data);
//             return;
//         } else {
//             alpha = alpha -> link;
//         }
//     }
//     // **Search for possible duplicate key.

//     // **Insert new record at head of chain.
//     push(myStack, key, data);
//     // **Insert new record at head of chain.
// }

// int main() {
//     int type = 3;
//     int nKeys = 10;
//     char inputStr[][15] = {
//         "compromise",
//         "accountant",
//         "presidency",
//         "photograph",
//         "temptation",
//         "brilliance",
//         "compromise",
//         "censorship",
//         "possession",
//         "federation"
//     };

//     // Initialize
//     HashTable myHashTable;
//     initHashTable(&myHashTable);

//     Stack **heads;
//     heads = (Stack **) malloc(32 * sizeof(Stack *));

//     for (int i = 0; i < 32; i++) {
//         Stack *myStack = (Stack *) malloc(sizeof(Stack));
//         initStack(myStack);

//         heads[i] = myStack;
//     }
//     myHashTable.table = heads;

//     for (int i = 0; i < nKeys; i++) {
//         int key = 0;
//         int strLen = strlen(inputStr[i]);

//         for (int j = 0; j < strLen; j++) {
//             key += (int) inputStr[i][j];
//         }

//         chainedHashTableInsert(&myHashTable, key, inputStr[i], type);
//     }

//     displayHTable(&myHashTable);
//     freeHTable(&myHashTable);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define newLine printf("\n")

// Reference:
// https://pythontutor.com/c.html#code=typedef%20struct%20Node%20%7B%0A%20%20char%20*key%3B%0A%20%20char%20*data%3B%0A%20%20struct%20Node*%20link%3B%0A%7D%20Node%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20Node%20*a%20%3D%20%28Node%20*%29%20malloc%28sizeof%28Node%29%29%3B%0A%20%20%0A%20%20a%20-%3E%20key%20%3D%20%22KEYS%22%3B%0A%0A%20%20return%200%3B%0A%7D&curInstr=3&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D
typedef struct Node {
    int key;
    char *data;
    struct Node* link;
} Node;

typedef struct Stack {
    Node * top;
} Stack;

typedef struct HashTable {
    Stack **table;
} HashTable;

void initStack(Stack *);
void initHashTable(HashTable *);
void push(Stack *, int, char *);

int hashFunction(int, int);
void displayHTable(HashTable *);

void freeStack(Stack *);
void freeHTable(HashTable *);
void chainedHashTableInsert(HashTable *, int, char *, int);

int main() {
    int type;
    if (scanf("%d", &type)) {}
    int nStrInputs;
    if (scanf("%d", &nStrInputs)) {}

    // Initialize
    HashTable myHashTable;
    initHashTable(&myHashTable);

    Stack **heads;
    heads = (Stack **) malloc(32 * sizeof(Stack *));

    for (int i = 0; i < 32; i++) {
        Stack *myStack = (Stack *) malloc(sizeof(Stack));
        initStack(myStack);

        heads[i] = myStack;
    }
    myHashTable.table = heads;

    // Reference:
    // https://pythontutor.com/c.html#code=int%20main%28%29%20%7B%0A%20%20char%20**strArray%3B%0A%20%20strArray%20%3D%20%28char%20**%29%20malloc%2810%20*%20sizeof%28char%20*%29%29%3B%0A%20%20%0A%20%20strArray%5B0%5D%20%3D%20%22qwerty%22%3B%0A%20%20strArray%5B5%5D%20%3D%20%22232hdf%22%3B%0A%0A%20%20free%28strArray%29%3B%0A%7D&curInstr=5&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D
    char **strInputs;  // Store string inputs for later use.
    strInputs = (char **) malloc(nStrInputs * sizeof(char *));

    for (int i = 0; i < nStrInputs; i++) {
        char *strTempInput = (char *) malloc(sizeof(char));
        if (scanf("%s", strTempInput)) {};
        strInputs[i] = strTempInput;

        int key = 0;
        int strLen = strlen(strInputs[i]);

        // Calculate key.
        for (int j = 0; j < strLen; j++) {
            key += (int) strInputs[i][j];
        }

        chainedHashTableInsert(&myHashTable, key, strInputs[i], type);
    }

    displayHTable(&myHashTable);

    // *Free manually allocated memories.
    freeHTable(&myHashTable);
    for (int i = 0; i < nStrInputs; i++) {
        free(strInputs[i]);
    }
    free(strInputs);
    // *Free manually allocated memories.

    return 0;
}

void chainedHashTableInsert(HashTable *myHashTable, int key, char *data, int type) {
    // **Search for possible duplicate key.
    int index = hashFunction(type, key);
    Stack *myStack = (myHashTable -> table)[index];
    Node *alpha = myStack -> top;

    while (alpha != NULL) {
        int isDataEqual = strcmp(alpha -> data, data);  // Returns 0 when strings are equal.
        if ((alpha -> key == key) && (isDataEqual == 0)) {
            printf("Duplicate key found: %s\n", data);
            return;
        } else {
            alpha = alpha -> link;
        }
    }
    // **Search for possible duplicate key.

    // **Insert new record at head of chain.
    push(myStack, key, data);
    // **Insert new record at head of chain.
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

void displayHTable(HashTable *myHashTable) {
    for (int i = 0; i < 32; i++) {
        Stack *myStack = (myHashTable -> table)[i];
        Node *alpha = myStack -> top;

        printf("%d: ", i);
        while (alpha != NULL) {
            printf("%s ", alpha -> data);
            alpha = alpha -> link;
        }
        newLine;
    }
};

// Reference:
// https://pythontutor.com/c.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstring.h%3E%0A%23include%20%3Cmath.h%3E%0A%0A%23define%20newLine%20printf%28%22%5Cn%22%29%0A%0A//%20Reference%3A%0A//%20https%3A//pythontutor.com/c.html%23code%3Dtypedef%2520struct%2520Node%2520%257B%250A%2520%2520char%2520*key%253B%250A%2520%2520char%2520*data%253B%250A%2520%2520struct%2520Node*%2520link%253B%250A%257D%2520Node%253B%250A%250Aint%2520main%2528%2529%2520%257B%250A%2520%2520Node%2520*a%2520%253D%2520%2528Node%2520*%2529%2520malloc%2528sizeof%2528Node%2529%2529%253B%250A%2520%2520%250A%2520%2520a%2520-%253E%2520key%2520%253D%2520%2522KEYS%2522%253B%250A%250A%2520%2520return%25200%253B%250A%257D%26curInstr%3D3%26mode%3Ddisplay%26origin%3Dopt-frontend.js%26py%3Dc_gcc9.3.0%26rawInputLstJSON%3D%255B%255D%0Atypedef%20struct%20Node%20%7B%0A%20%20%20%20char%20*key%3B%0A%20%20%20%20//%20char%20*data%3B%20%20//%20Not%20needed%20in%20this%20context.%0A%20%20%20%20struct%20Node*%20link%3B%0A%7D%20Node%3B%0A%0Atypedef%20struct%20Stack%20%7B%0A%20%20%20%20Node%20*%20top%3B%0A%7D%20Stack%3B%0A%0Avoid%20initStack%28Stack%20*myStack%29%20%7B%0A%20%20%20%20myStack%20-%3E%20top%20%3D%20NULL%3B%0A%7D%0A%0Avoid%20push%28Stack%20*myStack,%20char%20key%5B%5D%29%20%7B%0A%20%20%20%20Node%20*newNode%20%3D%20%28Node%20*%29%20malloc%28sizeof%28Node%29%29%3B%0A%20%20%20%20newNode%20-%3E%20key%20%3D%20key%3B%0A%20%20%20%20//%20newNode%20-%3E%20data%20%3D%20data%3B%20%20//%20Not%20needed%20in%20this%20context.%0A%20%20%20%20newNode%20-%3E%20link%20%3D%20NULL%3B%0A%0A%20%20%20%20if%20%28%28myStack%20-%3E%20top%29%20%3D%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20myStack%20-%3E%20top%20%3D%20newNode%3B%0A%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20newNode%20-%3E%20link%20%3D%20myStack%20-%3E%20top%3B%0A%20%20%20%20%20%20%20%20myStack%20-%3E%20top%20%3D%20newNode%3B%0A%20%20%20%20%7D%0A%7D%0A%0Avoid%20freeStack%28Stack%20*myStack%29%20%7B%0A%20%20%20%20if%20%28%28myStack%20-%3E%20top%29%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20Node%20*alpha%20%3D%20myStack%20-%3E%20top%3B%0A%20%20%20%20%20%20%20%20Node%20*beta%20%3D%20NULL%3B%0A%0A%20%20%20%20%20%20%20%20while%20%28alpha%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20beta%20%3D%20alpha%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20alpha%20%3D%20alpha%20-%3E%20link%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20free%28beta%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20Stack%20myStack%3B%0A%20%20initStack%28%26myStack%29%3B%0A%20%20%0A%20%20push%28%26myStack,%20%22qw%22%29%3B%0A%20%20push%28%26myStack,%20%2213de%22%29%3B%0A%20%20push%28%26myStack,%20%2232%22%29%3B%0A%20%20%0A%20%20freeStack%28%26myStack%29%3B%0A%20%20%0A%20%20return%200%3B%20%20%0A%7D&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D
void freeStack(Stack *myStack) {
    if ((myStack -> top) != NULL) {
        Node *alpha = myStack -> top;
        Node *beta = NULL;

        while (alpha != NULL) {
            beta = alpha;
            alpha = alpha -> link;
            free(beta);
        }
    }

    free(myStack);
}

void freeHTable(HashTable *myHashTable) {
    for (int i = 0; i < 32; i++) {
        Stack *myStack = (myHashTable -> table)[i];
        freeStack(myStack);
    };
}

// *Stack implementation
void initStack(Stack *myStack) {
    myStack -> top = NULL;
}

void initHashTable(HashTable *myHashTable) {
    myHashTable -> table = NULL;
}

void push(Stack *myStack, int key, char *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode -> key = key;
    newNode -> data = data;
    newNode -> link = NULL;

    if ((myStack -> top) == NULL) {
        myStack -> top = newNode;
    } else {
        newNode -> link = myStack -> top;
        myStack -> top = newNode;
    }
}
// *Stack implementation
