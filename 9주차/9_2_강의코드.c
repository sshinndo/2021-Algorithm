#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 13

typedef struct {
	int key;
	int probeCount; //조사 횟수
}Bucket;

typedef struct{
	Bucket A[M];
}HashType;

void init(HashType* HT){
	for(int i=0; i<M; i++){
		HT->A[i].key = 0;
		HT->A[i].probeCount = 0;
	}
}
int h(int key){
	return key % M ;
}

int h2(int key){
	return 11 - (key % 11) ;
}
int getNextBucketLinear(int v, int i){
	return (v + i) % M;
} // 단일 해싱

int getNextBucketQuadratic(int v, int i){
	return (v + i * i) % M; // 1차 군집화를 피하기 위해 * i
} // 이중 해싱

int getNextBucketDouble(int v, int i, int key){
	return (v + i * h2(key)) % M; 
} // 더블 해싱

int isEmpty(HashType* HT, int b){
	return HT->A[b].key == 0;
}

void insertItem(HashType* HT, int key){
	int v = h(key);
	int i = 0;
	int count = 0; // 조사 횟수
	
	while(i < M){
		count++;
		int b = getNextBucketLinear(v, i); // 단일 해싱
		// int b = getNextBucketQuadratic(v, i); // 이중 해싱
		// int b = getNextBucketDouble(v, i, key); // 더블 해싱

		if(isEmpty(HT, b)){
			HT->A[b].key = key;
			HT->A[b].probeCount = count;
			return;
		}
		else{
			i++;
		}
	}
}

void printHash(HashType* HT){
	printf("Bucket   key   Probe\n");
	printf("===================\n");

	for(int i=0;i<M; i++){
		printf("HT[%02d] : %2d   %d\n", i, HT->A[i].key, HT->A[i].probeCount);
	}
}

int main(){
	HashType HT;
	init(&HT);

	insertItem(&HT, 25); insertItem(&HT, 13); insertItem(&HT, 16);
	insertItem(&HT, 15); insertItem(&HT, 7); insertItem(&HT, 28);
	insertItem(&HT, 31); insertItem(&HT, 20); insertItem(&HT, 1);
	insertItem(&HT, 38);

	printHash(&HT);

	return 0;
}
