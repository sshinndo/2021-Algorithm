#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 13

typedef struct HashNode{
	int key;
	struct HashNode* next; // link field
}HashType; // Node와 동일하나 이름상 구분하기

void init(HashType* HT){
	for(int i=0;i<M;i++){
		HT[i].next = NULL;
	}
}

int h(int key){
	return key % M;
} // 모든 key 값은 M에 따라 자리가 정해진다!!

void insertItem(HashType* HT, int key){
	int v = h(key); // 위치가 정해짐
	HashType* node = (HashType*)malloc(sizeof(HashType));
	// add
	node->key = key;
	node->next = HT[v].next;
	HT[v].next = node;
}

int findElement(HashType* HT,int key){
	int v=h(key);
	int count =0;
	HashType* p;
	for(p=HT[v].next; p!=NULL; p=p->next){
		if(p->key == key){
			count++;
		}
	}
	return count;
}

int removeElement(HashType* HT, int key){
	int v = h(key);
	int count; //삭제가 되었다면 몇 개가 삭제되었는지 확인 index
	
	HashType* p= &HT[v];
	HashType* q; // 화살표 포인터 한 개 더

	while(p->next!=NULL){
		if (p->next->key == key){
			count++;
			q=p->next;
			p->next = q->next;
			free(q);
		}
		else{
			p=p->next;
		}
	}
	return count;
}

void printHash(HashType* HT){
	HashType* p;

	//
	for(int i=0;i<M;i++){
		printf("HT[%02d] : ",i);
		for(p=HT[i].next; p!= NULL; p = p->next){
			printf(" %d",p->key);
		}
		printf("\n");
	}
	//
}

int main(){
	HashType HT[M];
	init(HT);

	int key;

	srand(time(NULL)); // 

	for(int i=0;i<20;i++){
		insertItem(HT,rand()% 90 + 10);
	}
	printHash(HT);

	printf("\n Input search key: ");
	scanf("%d",&key);		
	printf("There are %d개 %d\n",findElement(HT,key),key);
	
	printf("\nInput delete key: ");
	scanf("%d",&key);
	printf("%d %d deleted \n\n",removeElement(HT,key), key);

	printHash(HT);
	return 0;
}
