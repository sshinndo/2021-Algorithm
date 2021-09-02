#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int n = 0;
int findElement(int A[], int key) {
	if (key < A[0]) return 0;
	else if (key > A[n - 1]) return n;
	
	for (int i = 0; i < n; i++) {
		if (key == A[i]) return i;
		else if (key > A[i] && key < A[i + 1]) return i+1;
	}
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

	free(ar);
	ar = NULL;
	return 0;
}
//mid = (int) { (float)(k - list[low]) / (list[high] - list[low]) }*(high - low) + low
