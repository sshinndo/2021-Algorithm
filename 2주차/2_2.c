#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int n;
	scanf("%d", &n);

	int *A = NULL;
	int minLoc;
	A = (int *)malloc(sizeof(int)*(n+1));
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	for (int pass = 1; pass <= n; pass++) {
		minLoc = pass;
		for (int j = pass + 1; j <= n; j++) {
			if (A[j] < A[minLoc])
				minLoc = j;
		}
		int tmp = A[pass];
		A[pass] = A[minLoc];
		A[minLoc] = tmp;
	}
	for (int i = 1; i <= n; i++) {
		printf(" %d", A[i]);
	}
	return;
}
