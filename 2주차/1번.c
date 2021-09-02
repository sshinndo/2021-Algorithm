#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//삽입정렬
int main(void) {
	int n;
	scanf("%d", &n);

	int *A = NULL;
	A = (int *)malloc(sizeof(int)*(n + 1));
	//원소 삽입 받기
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	//InsertionSort	
	for (int pass = 2; pass <= n; pass++) {
		int save = A[pass];
		int j = pass - 1;
		while (j >= 1 && A[j] > save) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = save;
	}
	for (int i = 1; i <= n; i++) {
		printf(" %d", A[i]);
	}
	return;
}
