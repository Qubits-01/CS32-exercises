#include <stdio.h>
#include <stdlib.h>

#define arrSize 8
#define newLine printf("\n")

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

    return i + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main() {
    int arr[arrSize] = {3, 2, 5, 6, 8, 4, 7, 1};
    int p = 0;
    int r = arrSize - 1;

    quicksort(arr, p, r);

    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    newLine;


    return 0;
}