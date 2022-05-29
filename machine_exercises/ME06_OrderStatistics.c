#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
    int noOfGroups =  ceilDiv((r - p) + 1, 5);
    
    // printf("    p: %d, r: %d\n", p, r);
    // printf("    A: ");
    // displayArray(A, 0, r + 1);
    // newLine;
    // printf("    noOfGroups: %d\n", noOfGroups);
    
    int medians[noOfGroups];
    int mediansIndex = 0;

    int tempGroup[5];
    int tempGroupIndex = 0;
    
    for (int i = p; i <= r; i++) {
        // printf("%d, ", A[i]);
        // newLine;
          
        // printf("      tempGroupIndex: %d, A[i]: %d\n", tempGroupIndex, A[i]);
        
        tempGroup[tempGroupIndex] = A[i];
        tempGroupIndex++;
        
        // printf("    unsortedTempGroup: ");
        // displayArray(tempGroup, 0, tempGroupIndex);
        // newLine;

        if ((tempGroupIndex == 5) || (i == r)) {
            // printf("tempGroupIndex: %d, i: %d\n", tempGroupIndex, i);
            
            insertion_sort(tempGroup, 0, tempGroupIndex);

            // printf("index: %d, value: %d\n", ((tempGroupIndex + 1) / 2) - 1, tempGroup[(tempGroupIndex + 1) / 2] - 1);
            medians[mediansIndex] = tempGroup[((tempGroupIndex + 1) / 2) - 1];
            mediansIndex++;
            
            // printf("    sortedTempGroup: ");
            // displayArray(tempGroup, 0, tempGroupIndex);
            // newLine;

            tempGroupIndex = 0;
        }
    }

    // printf("    unsortedMoM: ");
    // displayArray(medians, 0, noOfGroups);
    // newLine;

    return quick_select(medians, 0, noOfGroups - 1, (noOfGroups + 1) / 2);
    // insertion_sort(medians, 0, noOfGroups);
    // int medianOfMedians = medians[((noOfGroups + 1) / 2) - 1];
    
    // printf("    sortedMoM: ");
    // displayArray(medians, 0, noOfGroups);
    // newLine;
    
    // printf("    medianOfMedians: %d\n", medianOfMedians);
    
    // return medianOfMedians;
}

int median_partition(int A[], int p, int r){
	// Write your code here
    int median = median_of_medians(A, p, r);
    
    // printf("  median: %d, p: %d, r: %d\n", median, p, r);
    // printf("  A: ");
    // displayArray(A, 0, r);
    // newLine;

    int ind = -1;
    for (int i = p; i <= r; i++) {
        if (A[i] == median) {
            ind = i;
            break;
        }
    }
    
    // printf("  ind: %d\n", ind);

    // if (ind == -1) {
    //     printf("Error!!!\n");
    //     exit(1);
    // }

    int temp;
    temp = A[ind];
    A[ind] = A[r];
    A[r] = temp;
    // A[ind] = A[r];

    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            // A[i] = A[j];
        }
    }

    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;
    // A[i + 1] = A[r];

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
	if (scanf("%d", &T)) {};
	
	while(T-- > 0){
		if (scanf("%d", &M)) {};
		int arr[M];

		//read the elements of the input array
		for(int i=0; i<M; i++){
			if (scanf("%d", &arr[i])) {};
		}
        
        // printf("input: ");
        // displayArray(arr, 0, M);
        // newLine;
        
        // printf("sort: ");
        // insertion_sort(arr, 0, M);
        // displayArray(arr, 0, M);
        // newLine;

        // median_of_medians(arr, 0, M - 1);

		int median_index = ((M + 1) / 2);
		printf("Median: %d\n", quick_select(arr, 0, M - 1, median_index));
		
		// newLine;
	}
	
	return 0;
}