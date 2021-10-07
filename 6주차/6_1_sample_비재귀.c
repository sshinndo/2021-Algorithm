#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

typedef struct {
	int key; // 정수형 키
	char value[10]; // 문자형 배열
}element; // 사전 요소

typedef struct {
	element dict[SIZE]; // 사전 요소 구조체 배열
	int size; // 요소의 개수 count
}DictType;

void init(DictType *D) {
	D->size = 0;
}

void insertKey(DictType* D) {
	for (int i = 0; i < SIZE; i++) {
		D->dict[i].key = rand() % 30 + 1; //1~30 랜덤 숫자, 
		for (int j = 0; j < i; j++) {
			// 사전 key 값이기 때문에 난수 중복 제거도 필요
			// if (방금 만든 key == 이전에 만든 key 값) 이면
			if (D->dict[i].key == D->dict[j].key) {
				i--;
			}
		}
	}
}
void insertValue(DictType* D) {
	for (int i = 0; i < SIZE; i++) {
		D->dict[i].key = rand() % 30 + 1; //1~30 랜덤 숫자, 
		for (int j = 0; j < 5; j++) {
			D->dict[i].value[j] = rand() % 26 + 97;
		}
		D->size++;
	}
}
void makeDict(DictType *D) { // key 값을 생성 / 키에 해당하는 value 생성
	insertKey(D);
	insertValue(D);
}

void insertionSort(DictType* D) {
	int i, j;
	element item; // element : 정렬의 대상
	for (i = 1; i < SIZE; i++) {
		item = D->dict[i];
		for (j = i - 1; j >= 0 && D->dict[j].key > item.key; j--) {
			D->dict[j + 1] = D->dict[j];
		}
		D->dict[j + 1] = item;
	}
}
int rFindElement(DictType* D, int key, int low, int high) { // 재귀문, low == left, high == right
	int middle;
	if (low <= high) {
		middle = (low + high) / 2;
		if (key == D->dict[middle].key) {
			return middle;
		}
		else if (key < D->dict[middle].key) {
			return rFindElement(D, key, low, middle - 1);
		}
		else {
			return rFindElement(D, key, middle + 1, high);
		}
	}
	return -1; // 맨 위가 실행이 된 후 마지막
}
int FindElement(DictType* D, int key, int low, int high) {
	int middle;
	while (low <= high) {
		middle = (low + high) / 2;
		if (key == D->dict[middle].key)
			return middle;
		else if (key < D->dict[middle].key)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return -1;
}

void print(DictType* D) {
	printf("key         value \n================\n");
	for (int i = 0; i < D->size; i++) {
		printf("%2d         ", D->dict[i].key);
		for (int j = 0; j < 5; j++) {// 문자열 처리(5글자)
			printf("%c", D->dict[i].value[j]);
		}
		printf("\n");
	}
}
int main() {
	DictType D;
	init(&D);
	srand(time(NULL));

	makeDict(&D); // 사전이라도 만들어보기
	print(&D);
	getchar();

	printf("\n");
	insertionSort(&D); //정렬 함수
	print(&D); // 정렬 확인
	getchar();

	printf("\n검색할 키 값을 입력: ");
	int key;
	scanf("%d", &key);

	//int idx = rFindElement(&D, key, 0, SIZE - 1); // 0~ SIZE-1 : 검색 범위
	int idx = FindElement(&D, key, 0, SIZE - 1);

	if (idx == -1) {
		printf("\n 검색 실패 \n");
	}
	else {
		printf("\n위치 %d에서 키(Key) : %d, 값(Value): \n", idx + 1, key);
		for (int j = 0; j < 5; j++) {
			printf("%c", D.dict[idx].value[j]); // 여기선 D가 구조체 포인터가 아닌 변수이므로 
		}
		printf("이 검색 되었음\n");
	}
	return 0;
}
