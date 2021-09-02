#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	
	int* ar = NULL;
	ar = (int*)malloc(n * sizeof(int));
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}

	int pass, maxLoc, j, tmp;
	for (pass = n-1; pass >=0; pass--) {
		maxLoc = pass;
		for (j = pass - 1; j >=0 ; j--) {
			if (ar[j] > ar[maxLoc]) {
				maxLoc = j;
			}
		}
		tmp = ar[pass];
		ar[pass] = ar[maxLoc];
		ar[maxLoc] = tmp;
	}
	for (int i = 0; i < n; i++) {
		printf(" %d", ar[i]);
	}
	return 0;
}
