#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 9-1 분리연쇄법 해시테이블

int M=0;

typedef struct HashNode {
	int key;
	struct HashNode* next; // link field
}HashType; // Node와 동일하나 이름상 구분하기

void init(HashType* HT) {
	for (int i = 0; i<M; i++) {
		HT[i].next = NULL;
	}
}

int h(int key) {
	return key % M;
} // 모든 key 값은 M에 따라 자리가 정해진다!!

void insertItem(HashType* HT, int key) {
	int v = h(key); // 위치가 정해짐
	// 노드 생성
	HashType* node = (HashType*)malloc(1*sizeof(HashType));
	// add
	node->key = key;
	node->next = HT[v].next;
	HT[v].next = node;
}

int findElement(HashType* HT, int key) {
	int v = h(key);
	int count = 0;
	int isFind = 0;
	HashType* p;
	for (p = HT[v].next; p != NULL; p = p->next) {
		count++;
		if (p->key == key) {
			isFind = 1;
			break;
		}
		
	}
	return isFind==1 ? count : 0 ;
}

int removeElement(HashType* HT, int key) {
	int v = h(key);
	int count=0; //삭제가 되었다면 몇 개가 삭제되었는지 확인 index

	HashType* p = & HT[v];
	HashType* q; // 삭제될 대상의 노드 포인터

	while (p->next != NULL) {
		if (p->next->key == key) {
			count++;
			q = p->next;
			p->next = q->next;
			free(q);
		}
		else {
			p = p->next;
		}
	}
	return count;
}

void printHash(HashType* HT) {
	HashType* p;
	// 2중 for문
	for (int i = 0; i<M; i++) {
		for (p = HT[i].next; p != NULL; p = p->next) {
			printf(" %d", p->key);
		}
	}
	printf("\n");
}

void main() {

	scanf("%d", &M); getchar();

	// HashType HT 생성
	HashType *HT=NULL;
	HT = (HashType*)malloc(sizeof(HashType)*M);
	// HashType null값 초기화 및 연결
	init(HT);
	
	
	char func;
	int key;
	
	for (;;) {
		scanf("%c", &func); getchar();

		if (func == 'i') {
			scanf("%d", &key); getchar();
			insertItem(HT, key);
		}
		else if (func == 's') {
			scanf("%d", &key); getchar();
			printf("%d\n",findElement(HT, key));
		}
		else if (func == 'd') {
			scanf("%d", &key); getchar();
			printf("%d\n", removeElement(HT, key));
		}
		else if (func == 'p') {
			printHash(HT);
		}
		else if (func == 'e') { // exit
			break;
		}
	}

	/*
	printf("\n Input search key: ");
	scanf("%d", &key);
	printf("There are %d개 %d\n", findElement(HT, key), key);

	printf("\nInput delete key: ");
	scanf("%d", &key);
	printf("%d %d deleted \n\n", removeElement(HT, key), key);

	printHash(HT);
	*/
}
