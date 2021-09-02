#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int NoSearchKey = -1;
int n = 0;
int rFE(int A[], int key, int left, int right) {
	if (left > right){
		if (A[right] <= key) return right;
		else return NoSearchKey;
	}
	int mid = (left + right) / 2;
	
	if (key == A[mid]) return mid;
	else if (key < A[mid]) return rFE(A, key, left, mid - 1);
	else { // if k > A[mid]
		return rFE(A, key, mid + 1, right);
	}
}
int findElement(int A[], int key) {
	return rFE(A, key, 0, n - 1);
}
int main() {
	int key;
	scanf("%d %d", &n, &key);

	int *ar = NULL;
	ar = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	int index = findElement(ar, key);
	
	printf(" %d", index);
	return 0;
}
//mid = (int) { (float)(k - list[low]) / (list[high] - list[low]) }*(high - low) + low
