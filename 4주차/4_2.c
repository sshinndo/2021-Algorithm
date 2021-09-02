#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int H[100] = { 0 }; //힙
int n = 0; // 힙의 크기(총 키의 개수)
int account=0;
void upHeap(int i) { //동일
	if (i == 1) return;
	if (H[i / 2] >= H[i]) return;
	//swap
	int tmp = H[i / 2];
	H[i / 2] = H[i];
	H[i] = tmp;
	// 부모<=자식 이면 swap 
	upHeap(i / 2);
	return;
}
void downHeap(int i, int last) { // 동일
	int left = 2 * i; int right = 2 * i + 1;
	if (left > last) return; // external node 경우
	int greater = left;
	if (right <= last) {
		if (H[right] > H[greater])
			greater = right;
	}
	if (H[i] >= H[greater]) return;
	//부모>=자식 이면 swap
	int tmp = H[i];
	H[i] = H[greater];
	H[greater] = tmp;
	//swap
	downHeap(greater,last);
}
void insertItem(int key) { //동일
	H[n + 1] = key;
	upHeap(n + 1);
	n = n + 1;
	return;
}
void buildHeap() {
	int key;
	for (int i = 1; i <= account;i++) {
		scanf("%d", &key);
		insertItem(key);
	}
	return;
}
void inPlaceHeapSort() {
	buildHeap();
	for (int i = n; i >= 2; i--) {
		int tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;
		downHeap(1,i-1);
	}
	return;
}
void printArray() {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}
int main() {
	scanf("%d", &account);
	inPlaceHeapSort();
	printArray();
}
