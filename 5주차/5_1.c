#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int n=0;

int rMergeSort(int A[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		rMergeSort(A, left, mid);
		rMergeSort(A, mid + 1, right);
		merge(A, left, mid, right);
	}
	return A;
}
int mergeSort(int A[]) { //분할
	rMergeSort(A, 0, n - 1);
	return A;
}
int merge(int A[],int left,int mid,int right) {//합병
	int i = left; int k = left;
	int j = mid + 1;
	int B[10000] = { 0 };

	while (i <= mid&&j <= right) {
		if (A[i] <= A[j]) B[k++] = A[i++];
		else B[k++] = A[j++];
	}
	while (i <= mid) B[k++] = A[i++];
	while (j <= right) B[k++] = A[j++];
	for (k = left; k <= right; k++) {
		A[k] = B[k];
	}
	return A;
}
void print(int A[]) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	return;
}
int main(void) {
	scanf("%d", &n);
	int A[10000];

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	mergeSort(A);

	print(A);
	return 0;
}
