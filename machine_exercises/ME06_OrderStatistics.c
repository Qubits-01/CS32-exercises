#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define newLine printf("\n")

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
	r++;		

	int noOfGroups = ceil(r / 5);
	int tempGroup[5];
	int tempGroupCtr = 0;
	int *medians;
	medians = (int *) malloc(sizeof(int) * noOfGroups);
	// int medians[2000];
	int mediansCtr = 0;

	for (int i = p; i < r + 1; i++) {
		tempGroup[i % 5] = A[i];
		tempGroupCtr++;

		if ((tempGroupCtr == 5) || (i + 1 == r)) {
			insertion_sort(tempGroup, 0, tempGroupCtr);
			int medianOfTempGroup = floor((tempGroupCtr + 1) / 2);
			medians[mediansCtr] = tempGroup[medianOfTempGroup - 1];

			mediansCtr++;
			tempGroupCtr = 0;
		}
	}
  
	// Find the median of medians.
	int medianRank = floor((noOfGroups + 1) / 2);
	int medianOfMedians = quick_select(medians, 0, noOfGroups - 1, medianRank);
	free(medians);

	return medianOfMedians;
}

int median_partition(int A[], int p, int r){
	// Write your code here
	int median = median_of_medians(A, p, r);

	// Find index ind of median.
	int ind;
	for (int i = 0; i <= r; i++) {
		if (A[i] == median) {
			ind = i;
			break;
		}
	}

	// Swap A[ind] with A[r].
	int temp;
	temp = A[ind];
	A[ind] = A[r];
	A[r] = temp;

	// A[ind] = A[r];

	int x = A[r];
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;

			// Exchange A[i] with A[j].
			int temp;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;

			// A[i] = A[j];
		}
	}

	// Exchange A[i + 1] with A[r].
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
	scanf("%d", &T);
	
	while (T-- > 0) {
		scanf("%d", &M);

		int *myArray;
		myArray = (int *) malloc(sizeof(int) * M);
		// int myArray[100];

		//read the elements of the input array
		for (int i = 0; i < M; i++){
			scanf("%d", &myArray[i]);
		}

		int median_index = ((M + 1) / 2);
		printf("Median: %d\n", quick_select(myArray, 0, M - 1, median_index));

		free(myArray);
	}

    return 0;
}