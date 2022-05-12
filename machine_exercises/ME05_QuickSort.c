// #include <stdio.h>
// #include <stdlib.h>

// #define arrSize 8
// #define prime 13
// #define newLine printf("\n")

// void displayArr(int myArr[]) {
//     for (int i = 0; i < arrSize; i++) {
//         printf("%d ", myArr[i]);
//     }
//     newLine;
// }

// void displayArrWithRange(int myArr[], int left, int right) {
//     for (;left < right; left++) {
//         printf("%d ", myArr[left]);
//     }
//     newLine;
// }

// int partition(int A[], int p, int r) {
//     int x = A[r];
//     int i = p - 1;

//     for (int j = p; j <= r - 1; j++) {
//         if (A[j] <= x) {
//             i++;
//             int temp = A[i];
//             A[i] = A[j];
//             A[j] = temp;
//         }
//     }

//     int temp = A[i + 1];
//     A[i + 1] = A[r];
//     A[r] = temp;

//     displayArrWithRange(A, p, r + 1);
    
//     return i + 1;
// }

// void quicksort(int A[], int p, int r) {
//     if (p < r) {
//         int q = partition(A, p, r);
//         quicksort(A, p, q - 1);
//         quicksort(A, q + 1, r);
//     }
// }


// void shuffleArr(int newArr[], int oldArr[]) {
//     int newIndices[arrSize];
//     for (int i = 0; i < arrSize; i++) {
//         newIndices[i] = ((i + 1) * prime) % arrSize;
//     }

//     for (int i = 0; i < arrSize; i++) {
//         newArr[i] = oldArr[newIndices[i]];
//     }
// }

// int main() {
//     int arr[arrSize] = {3, 2, 5, 6, 8, 4, 7, 1};
//     int p = 0;
//     int r = arrSize - 1;

//     int newArr[arrSize];
//     shuffleArr(newArr, arr);
//     displayArr(newArr);

//     quicksort(newArr, p, r);
//     displayArr(newArr);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

#define arrSize 8
#define prime 13
#define newLine printf("\n")

void displayArr(int myArr[]) {
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    newLine;
}

void displayArrWithRange(int myArr[], int left, int right) {
    for (;left < right; left++) {
        printf("%d ", myArr[left]);
    }
    newLine;
}

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    displayArrWithRange(A, p, r + 1);
    
    return i + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}


void shuffleArr(int newArr[], int oldArr[]) {
    int newIndices[arrSize];
    for (int i = 0; i < arrSize; i++) {
        newIndices[i] = ((i + 1) * prime) % arrSize;
    }

    for (int i = 0; i < arrSize; i++) {
        newArr[i] = oldArr[newIndices[i]];
    }
}

int main() {
    int noOfTestcases;
    if (scanf("%d", &noOfTestcases)) {};

    for (int _ = 0; _ < noOfTestcases; _++) {
        // Get and parse the input data.
        int myArr[arrSize];
        for (int i = 0; i < arrSize; i++) {
            int temp;
            if (scanf("%d", &temp)) {};
            myArr[i] = temp;
        }
        
        // Shuffle the array.
        int newArr[arrSize];
        shuffleArr(newArr, myArr);
        displayArr(newArr);

        // Sort the array.
        quicksort(newArr, 0, arrSize - 1);
        displayArr(newArr);
    }

    return 0;
}