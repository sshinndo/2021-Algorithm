#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int n = 0;
void quickSort(int *data, int start, int end) {
	if (start >= end) return; //원소가 1개인 경우
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;
	while (i <= j) { //엇갈릴 때까지 반복
		while (data[i] <= data[key]) i++;//키값보다 큰 값을 만날때까지
		while (data[j] >= data[key] && j > start) j--;//키값보다 작은 값을 만날때까지
		if (i > j) {//현재 엇갈린 상태면 키 값과 교체
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
		quickSort(data, start, j - 1);
		quickSort(data, j + 1, end);
	}
}
void print(int A[]) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	return;
}
int main(void) {
	scanf("%d", &n);
	int *A = NULL;
	A = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	quickSort(A, 0, n - 1);
	print(A);
	return 0;
}
