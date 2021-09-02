#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int H[100] = { 0 }; //힙
int n = 0; // 힙의 크기(총 키의 개수)
void upHeap(int i) {
	if (i == 1) return;
	if (H[i / 2] >= H[i]) return;
	//swap
	int tmp;
	tmp = H[i / 2];
	H[i / 2] = H[i];
	H[i] = tmp;
	//
	upHeap(i / 2);
	return;
}
void downHeap(int i) {
	int left = 2 * i; int right = 2 * i + 1;
	if (left > n) return; // external node 경우
	int greater = left;
	if (right <= n) {
		if (H[right] > H[greater])
			greater = right;
	}
	if (H[i] >= H[greater]) return;
	//swap
	int tmp = H[i];
	H[i] = H[greater];
	H[greater] = tmp;
	//
	downHeap(greater);
}
void insertItem(int key) {
	H[n + 1] = key;
	upHeap(n + 1);
	n = n + 1;
	printf("0\n");
	return;
}
int removeMax() {
	int del_key = H[1];
	H[1] = H[n];
	downHeap(1);
	n = n - 1;
	return del_key;
}
void printHeap() {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}printf("\n");
}
int main() {
	char func;
	int key; int del;
	while (1) {
		scanf("%c", &func);
		getchar();
		if (func == 'i') {
			scanf("%d", &key);
			getchar();
			insertItem(key);
		}
		if (func == 'd') {
			del = removeMax();
			printf("%d\n", del);
		}
		if (func == 'p') printHeap();
		if (func == 'q') break;
	}
}
