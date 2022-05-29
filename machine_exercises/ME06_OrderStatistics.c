#include<stdio.h>
#include<stdlib.h>

int quick_select(int[], int, int, int);
int median_partition(int[], int, int);
int median_of_medians(int[], int, int);

void insertion_sort(int[], int, int);
int ceilDiv(int, int);

int main(){
	int T, M;
	if (scanf("%d", &T)) {};
	
	while(T-- > 0){
		if (scanf("%d", &M)) {};
		int arr[M];

		//read the elements of the input array
		for(int i=0; i<M; i++) if (scanf("%d", &arr[i])) {};
        
		int median_index = ((M + 1) / 2);
		printf("Median: %d\n", quick_select(arr, 0, M - 1, median_index));
	}
	
	return 0;
}

int quick_select(int A[], int p, int r, int rank) {
	// Write your code here
    if (p == r) return A[p];

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

int median_partition(int A[], int p, int r) {
	// Write your code here
    int median = median_of_medians(A, p, r);

    int ind = -1;
    for (int i = p; i <= r; i++) {
        if (A[i] == median) {
            ind = i;
            break;
        }
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

int median_of_medians(int A[], int p, int r) {
	// Write your code here
    int noOfGroups =  ceilDiv((r - p) + 1, 5);
    int medians[noOfGroups];
    int mediansIndex = 0;

    int tempGroup[5];
    int tempGroupIndex = 0;
    
    for (int i = p; i <= r; i++) {
        tempGroup[tempGroupIndex] = A[i];
        tempGroupIndex++;

        if ((tempGroupIndex == 5) || (i == r)) {
            insertion_sort(tempGroup, 0, tempGroupIndex);

            medians[mediansIndex] = tempGroup[((tempGroupIndex + 1) / 2) - 1];
            mediansIndex++;

            tempGroupIndex = 0;
        }
    }

    return quick_select(medians, 0, noOfGroups - 1, (noOfGroups + 1) / 2);
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
