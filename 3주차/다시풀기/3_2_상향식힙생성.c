#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {
	int H[SIZE];
	int n; // 원소의 개수
} Heap;

void initHeap(Heap *heap) {
	heap->n = 0; //원소의 개수 초기화
}

void printHeap(Heap *heap) {
	for (int i = 1; i <= heap->n; i++) {
		printf(" %d", heap->H[i]);
	}
	printf("\n");
	return;
}
void downHeap(Heap *heap, int i) {
	int left = 2 * i, right = 2 * i + 1;
	if (left > heap->n) return; // external node인 경우
	
	int greater = left;
	if (right <= heap->n) {
		if (heap->H[right] > heap->H[greater])
			greater = right;
	}
	if (heap->H[i] > heap->H[greater]) return;
	
	// else: swap
	int tmp = heap->H[i];
	heap->H[i] = heap->H[greater];
	heap->H[greater] = tmp;
	
	downHeap(heap, greater);
}
void buildHeap(Heap *heap) {
	for (int i = (heap->n)/2; i >= 1; i--) {
		downHeap(heap, i);
	}
}
void main() {
	Heap heap;

	initHeap(&heap);

	int numOfKey;
	int newKey;

	scanf("%d", &numOfKey);
	heap.n = numOfKey;

	for (int i = 1; i <= numOfKey; i++) {
		scanf("%d", &heap.H[i]);
	}

	buildHeap(&heap);

	printHeap(&heap);

	return;
}
