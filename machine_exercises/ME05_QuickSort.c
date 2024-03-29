#include<stdio.h>
#include<stdlib.h>

#define newLine printf("\n");

// void insertion_sort(int A[], int from, int to) {
//     for(int i = from; i < to; i++) {
//         for(int j = i + 1; j > from && A[j] < A[j - 1]; j--) {
//             int temp = A[j - 1];
//             A[j - 1] = A[j];
//             A[j] = temp;
//         }
//     }
// }

void displayArray(int A[], int from, int to) {
    for (int i = from; i < to; i++) {
        printf("%d ", A[i]);
    }
    newLine;
}

int ceilDiv(int numerator, int denominator) {
    int floorQuotient = numerator / denominator;
    int ceilQuotient;

    if (numerator > (floorQuotient * denominator)) {
        ceilQuotient = floorQuotient + 1;
    } else {
        ceilQuotient = floorQuotient;
    }

    return ceilQuotient;
}

void insertion_sort(int A[], int from, int to) {
  for (int step = from + 1; step < to; step++) {
    int key = A[step];
    int j = step - 1;
    
    while ((key < A[j]) && (j >= 0)) {
      A[j + 1] = A[j];
      --j;
    }
    
    A[j + 1] = key;
  }
}

int quick_select(int A[], int p, int r, int k);

int median_of_medians(int A[], int p, int r){
	// Write your code here
    int noOfGroups =  ceilDiv(r + 1, 5);

    // printf("noOfGroups: %d, r: %d\n", noOfGroups, r);
    int medians[noOfGroups];
    int mediansIndex = 0;

    int tempGroup[5];
    int tempGroupIndex = 0;
    
    for (int i = p; i <= r; i++) {
        // printf("%d, ", A[i]);
        // newLine;

        tempGroup[tempGroupIndex] = A[i];
        tempGroupIndex++;

        if ((tempGroupIndex == 5) || (i == r)) {
            // printf("tempGroupIndex: %d, i: %d\n", tempGroupIndex, i);
            
            insertion_sort(tempGroup, 0, tempGroupIndex);

            medians[mediansIndex] = tempGroup[(tempGroupIndex + 1) / 2] - 1;
            mediansIndex++;
            
            // printf("tempGroup: ");
            // displayArray(tempGroup, 0, tempGroupIndex);

            tempGroupIndex = 0;
        }
    }

    // printf("Median of medians: ");
    // displayArray(medians, 0, noOfGroups);
    // newLine;

    return quick_select(medians, 0, noOfGroups - 1, (noOfGroups + 1) / 2);
}

int median_partition(int A[], int p, int r){
	// Write your code here
    int median = median_of_medians(A, p, r);
    
    // printf("A: ");
    // displayArray(A, p, r + 1);
    // newLine;

    int ind = -1;
    for (int i = 0; i <= 2000; i++) {
      // printf("i: %d, median: %d, A: %d\n", i, median, A[i]);
        if (A[i] == median) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        printf("Error!!!\n");
        exit(1);
    }

    int temp;
    temp = A[ind];
    A[ind] = A[r];
    A[r] = temp;

    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return i + 1;
}

int quick_select(int A[], int p, int r, int rank){
	// Write your code here
    if (p == r) {
        return A[p];
    }

    int q = median_partition(A, p, r);
    int k = q - p + 1;

    if (rank == k) {
        return A[q];
    } else if (rank < k) {
        return quick_select(A, p, q - 1, rank);
    } else {
        return quick_select(A, q + 1, r, rank - k);
    }
}

int main(){
	int T, M;
	scanf("%d", &T);
	while(T-- > 0){
		scanf("%d", &M);
		int arr[M];

		//read the elements of the input array
		for(int i=0; i<M; i++){
			scanf("%d",&arr[i]);
		}

        // displayArray(arr, 0, M);
    
        // printf("sort: ");
        // insertion_sort(arr, 0, M);
        // displayArray(arr, 0, M);
        // newLine;

        // median_of_medians(arr, 0, M - 1);
        // newLine;

		int median_index = ((M+1)/2);
		printf("Median: %d\n", quick_select(arr, 0, M-1, median_index));
	}
	
	return 0;
}