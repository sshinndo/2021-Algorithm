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

void upHeap(Heap *heap) {
	int lastIndex = heap->n;
	int lastKey = heap->H[lastIndex];

	while (lastIndex != 1 && lastKey > heap->H[lastIndex/2]) {
		heap->H[lastIndex] = heap->H[lastIndex / 2];
		lastIndex /= 2;
	}
	heap->H[lastIndex] = lastKey;
}

void insertItem(Heap *heap, int key) {
	(heap->n)++;

	heap->H[heap->n] = key; // n위치에 key 삽입

	upHeap(heap);
	printf("0\n");
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

int removeRoot(Heap *heap) {
	int k = heap->H[1]; // root 의 key 대입

	heap->H[1] = heap->H[heap->n];

	(heap->n)--;
	downHeap(heap, 1); // 정렬

	return k;
}

void main() {
	Heap heap;

	initHeap(&heap);

	char func;
	int newKey;

	while (1) {
		scanf("%c", &func); getchar();
		if (func == 'i') {
			scanf("%d", &newKey); getchar();
			insertItem(&heap, newKey);
		}
		if (func == 'd') { 
			printf("%d\n", removeRoot(&heap));
		}
		if (func == 'p') {
			printHeap(&heap);
		}
		if (func == 'q') {
			break;
		}
	}	
	return;
}
