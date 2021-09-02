#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int key;
	struct Node *next;
}Node;
Node *hash; //해시 테이블
int M = 0; //해시 테이블 크기

int h(int x) {
	x = x % M;
	return x;
}
int findElement(int key) {
	
}
void insertItem(int x) {
	int v = h(x);

	Node *p = hash + v;
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->key = x;
	newNode->next = NULL;

	//첫 리스트이면
	if (p->next == NULL) {
		p->next = newNode;
	}
	//이미 저장된 키가 있다면
	else {
		newNode->next = p->next;
		p->next = newNode;
	}
}
int searchItem(int x) {
	int v = h(x), count = 0;
	Node *p = hash + v;
	if (p->next == NULL) {
		return count;
	}
	else {
		while (1) {
			p = p->next;
			count++;
			if (p->key == x) {
				return count;
			}
			if (p->next == NULL) {
				return 0;
			}
		}
	}
}
int removeItem(int x) {
	int v = h(x), count = 0;
	Node *p = hash + v;
	Node *pp = hash + v;
	if (p->next == NULL) {
		return 0;
	}
	else {
		while (1) {
			p = p->next;
			count++;
			if (p->key == x) {
				while (pp->next != p) {
					pp = pp->next;
				}
				pp->next = p->next;
				free(p);
				return count;
			}
			if (p->next == NULL) {
				return 0;
			}
		}
	}
}
void printTable() {
	Node *p;
	for (int i = 0; i < M; i++) {
		p = hash + i;
		if (p->next != NULL) {
			while (p->next != NULL) {
				p = p->next;
				printf(" %d", p->key);
			}			
		}
	}printf("\n");
}
void freeTable() {
	Node *p, *q;
	for (int i = 0; i < M; i++) {
		if ((hash + i)->next != NULL) {
			p = (hash + i)->next;
			q = p;
			while (q->next != NULL) {
				p = p->next;
				free(q);
				q = p;
			}
		}
	}
	free(hash);
}
void main(void) {
	scanf("%d", &M);
	char func;
	int elem;

	hash = (Node*)malloc(M * sizeof(Node));
	//각 해쉬배열 초기화
	for (int i = 0; i < M; i++) {
		(hash + i)->key = NULL;
		(hash + i)->next = NULL;
	}
	while (1) {
		scanf("%c", &func);
		if (func == 'i') {
			scanf("%d", &elem);
			getchar();
			insertItem(elem);
		}
		else if (func == 's') {
			scanf("%d", &elem);
			getchar();
			printf("%d\n", searchItem(elem));
		}
		else if (func == 'd') {
			scanf("%d", &elem);
			getchar();
			printf("%d\n", removeItem(elem));
		}
		else if (func == 'p') {
			printTable();
			getchar();
		}
		else if (func == 'e') {
			break;
		}
	}
	freeTable();
}
