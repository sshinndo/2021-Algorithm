#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// 7-1. 교재 내용을 바탕으로
typedef struct TreeNode {
	int key;
	struct TreeNode *parent, *left, *right;
}TreeNode;

typedef struct {
	TreeNode* root;
}TreeType;

void init(TreeType* T) {
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	T->root->parent = T->root->left = T->root->right = NULL;
}

int isExternal(TreeNode* w) {
	return (w->left == NULL && w->right == NULL);
}

TreeNode* treeSearch(TreeNode *v, int k) {
	if (isExternal(v))
		return v;

	if (k == v->key)
		return v;
	else if (k < v->key)
		return treeSearch(v->left, k);
	else // k > v->key
		return treeSearch(v->right, k);
}

void expandExternal(TreeNode* w) {
	TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));

	l->left = l->right = NULL;
	l->parent = w; // 중요!

	r->left = r->right = NULL;
	r->parent = w; // 

	w->left = l;
	w->right = r;	
}

TreeNode* sibling(TreeNode* z) {
	if (z->parent->left == z) 
		return z->parent->right;

	else // z는 right 라는 소리이므로
		return z->parent->left; // 형제노드인 left를 반환
}

TreeNode* reduceExternal(TreeType* T, TreeNode* z) {
	
	TreeNode* w = z->parent; // z : w의 보조노드가 날라온 것
	TreeNode* g = w->parent;
	TreeNode* zs = sibling(z);
	zs->parent = g;

	if (g == NULL) //
		T->root = zs;
	else
		if (w == g->left)
			g->left = zs;
		else
			g->right = zs;
	free(w);
	free(z);

	return zs;
}

void insertItem(TreeType* T, int k){
	// 1. 위치를 찾고
	// 2. 외부 노드를 삽입해야
	// k : key
	TreeNode* w = treeSearch(T->root, k);
	if (!isExternal(w)) {
		return;
	}
	else { // if (isExternal(w))
		w->key = k;
		expandExternal(w); // 모조 노드를 외부 노드로 확장함수
	}
}

TreeNode* inOrderSucc(TreeNode* w) {
	w = w->right;
	while (w->left != NULL) {
		w = w->left;
	}
	return w;
}
int removeElement(TreeType* T, int k) {
	TreeNode* w, *z; // case 1
	
	TreeNode* y; // 삭제 case 2에 필요한 변수

	//삭제하고자 하는 키 값의 위치를 w에
	w = treeSearch(T->root, k);

	//-------- 삭제 : Case1 의사코드 예시

	if (isExternal(w)) //삭제하려고 하는 키 값이 없을 때
		return -1;
	
	z = w->left; // 왼쪽 노드 삽입
	if (!isExternal(z)) 
		z = w->right; // 오른쪽 노드 삽입
	
	if (isExternal(z))
		reduceExternal(T, z);
	//-------- 삭제 : Case1 의사코드 예시
	//-------- 삭제 : Case2 의사코드 예시
	else{
		z = inOrderSucc(w); //중위순회 계승자를 찾는 함수
		y = z->parent;
		w->key = y->key;
		reduceExternal(T, z);
	}
	return k;
	//-------- 삭제 : Case2 의사코드 예시
		
}

void preOrder(TreeNode* root) {
	if (isExternal(root)) // 외부노드이면 재귀타지말고 return
		return;
	printf(" [%d]", root->key);
	preOrder(root->left);
	preOrder(root->right);
}
int main() {
	TreeType* T = (TreeType*)malloc(sizeof(TreeType));
	// TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode)); // 로 root 설정하고, TreeType을 제거하여 사용해도 된다.
	init(T);

	insertItem(T, 9);
	insertItem(T, 2);
	insertItem(T, 1);
	insertItem(T, 7);
	insertItem(T, 15);
	insertItem(T, 11);
	insertItem(T, 8);
	//--------------삭제용-----------
	insertItem(T, 5); // 테스트 후 지울 것
	insertItem(T, 3); // 테스트 후 지울 것
	insertItem(T, 4); // 테스트 후 지울 것
	//--------------삭제용-----------

	// printf("전위순회 preOrder");
	preOrder(T->root); printf("\n");
	getchar();

	printf("삭제할 키 입력:");
	int key;
	scanf("%d", &key);
	removeElement(T, key);

	// 잘 삭제 되었는지 전위순회로 출력 테스트 확인
	preOrder(T->root); printf("\n");

	return 0;

}
