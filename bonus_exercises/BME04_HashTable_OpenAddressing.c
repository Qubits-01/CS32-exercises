// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define tableSize 32
// #define newLine printf("\n")

// int getHashFunction1(int key) {
//     return key % tableSize;
// }

// int getHashFunction2(int key) {
//     return (((1731 * key + 520123) % 524287) % tableSize) | 1;
// }

// int getMainHashFunction(int key, int i) {
//     return (getHashFunction1(key) + (i * getHashFunction2(key))) % tableSize;
// }

// void displayHashTable(int hashTable[tableSize]) {
//     for (int i = 0; i < tableSize; i++) {
//         printf("%d: %d", i, hashTable[i]);
//         newLine;
//     }
// }

// int main() {
//     int hashTable[tableSize];
    
//     // Initialize the hashTable.
//     for (int i = 0; i < tableSize; i++) {
//         hashTable[i] = 0;
//     }

//     int collissionCounter = 0;
//     for (int _ = 0; _ < tableSize; _++) {
//         int currentInput;
//         if (scanf("%d", &currentInput)) {};

//         int i = 0;
//         int currentIndex = getMainHashFunction(currentInput, i);

//         while (true) {
//             if (hashTable[currentIndex] == currentInput) {
//                 printf("Duplicate key found\n");
//                 exit(0);
//             } else if (hashTable[currentIndex] > 0) {
//                 collissionCounter++;
//                 i++;
//                 currentIndex = getMainHashFunction(currentInput, i);
//                 continue;
//             } else if (hashTable[currentIndex] == 0) {
//                 hashTable[currentIndex] = currentInput;
//                 break;
//             }
//         }
//     }

//     displayHashTable(hashTable);
//     printf("%d\n", collissionCounter);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tableSize 256
#define newLine printf("\n")

int getHashFunction1(int key) {
    return key % tableSize;
}

int getHashFunction2(int key) {
    return (((1731 * key + 520123) % 524287) % tableSize) | 1;
}

int getMainHashFunction(int key, int i) {
    return (getHashFunction1(key) + (i * getHashFunction2(key))) % tableSize;
}

void displayHashTable(int hashTable[tableSize]) {
    for (int i = 0; i < tableSize; i++) {
        printf("%d: %d", i, hashTable[i]);
        newLine;
    }
}

int main() {
    int hashTable[tableSize];
    
    // Initialize the hashTable.
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = 0;
    }

    int collissionCounter = 0;
    for (int _ = 0; _ < tableSize; _++) {
        int currentInput;
        if (scanf("%d", &currentInput)) {};

        int i = 0;
        int currentIndex = getMainHashFunction(currentInput, i);

        while (true) {
            if (hashTable[currentIndex] == currentInput) {
                printf("Duplicate key found\n");
                exit(0);
            } else if (hashTable[currentIndex] > 0) {
                collissionCounter++;
                i++;
                currentIndex = getMainHashFunction(currentInput, i);
                continue;
            } else if (hashTable[currentIndex] == 0) {
                hashTable[currentIndex] = currentInput;
                break;
            }
        }
    }

    displayHashTable(hashTable);
    printf("%d\n", collissionCounter);

    return 0;
}
