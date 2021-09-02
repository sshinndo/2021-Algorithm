#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int H[100] = { 0 }; //힙
int n=0; // 힙의 크기(총 키의 개수)
void downHeap(int i) { //그대로 사용
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
void printHeap() {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}printf("\n");
}
void buildHeap() {
	for (int i = n / 2; i >= 1; i--) {
		downHeap(i);
	}
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}
	buildHeap();
	printHeap();
}
