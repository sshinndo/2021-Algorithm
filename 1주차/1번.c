#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
	char elem;
	struct ListNode *prev;
	struct ListNode *next;
} Node;
int traversal(Node *list);
void add(Node *list, int r, char e);
void removeNode(Node *list, int r);
void get(Node *list, int r);
void print(Node *list);
int main() {
	int num, i, r;
	Node *head = NULL, *tail = NULL;
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	
	head->next = tail;
	tail->prev = head;

	char func, e;
	scanf("%d", &num);
	
	for (i = 0; i < num; i++) {
		getchar();
		scanf("%c", &func);
		if (func == 'A') {
			scanf("%d %c", &r, &e);
			add(head, r, e);			
		}
		if (func == 'D') {
			scanf("%d", &r);
			removeNode(head, r);			
		}
		if (func == 'G') {
			scanf("%d", &r);
			get(head, r);			
		}
		if (func == 'P') {
			print(head);			
		}
	}
	free(tail);
	free(head);
	return 0;
}
int traversal(Node *list) {
	Node *p = NULL;	
	p = list->next;
	int cnt = 0;
	while (p->next != NULL) {
		p = p->next;
		cnt++;
	}
	return cnt;
}
void add(Node *list, int r, char e) { //list 순위 r에 원소 e 추가
	int i, n;
	n = traversal(list);
	Node *p = NULL; // 추가할 노드
	p = (Node *)malloc(sizeof(Node));
	if (r<1 || r>n + 1) {
		printf("invalid position\n");
		return 0;
	}
	for (i = 1; i < r; i++) {
		list = list->next;
	} //r=1일때는 for문 생략
	p->next = list->next;
	p->prev = list;
	p->elem = e;
	list->next = p;
}
void removeNode(Node *list, int r) { // list 순위 r의 원소 삭제
	Node *p;
	int n;
	n = traversal(list);
	if (r<1 || r>n) {
		printf("invalid position\n");
		return 0;
	}
	int i;
	p = (Node *)malloc(sizeof(Node));

	for (i = 1; i <= r-1; i++) {
		list = list->next;
	}
	p = list->next;
	list->next = p->next;
	(list->next)->prev = p->prev;
	free(p);
}
void get(Node *list, int r) { // list의 순위 r의 원소 반환
	Node *p = NULL;
	p = (Node *)malloc(sizeof(Node));
	p = list->next;
	int n, i;
	n = traversal(list);
	if (r<1 || r>n) {
		printf("invalid position\n");
		return 0;
	}
	for (i = 1; i <= r - 1; i++) {
		p = p->next;
	}
	printf("%c\n", p->elem);
}

void print(Node *list) { // 모든 원소 순위대로 공백없이 출력
	Node *p = list->next;
	while (p->next != NULL) {
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}
