//내가짠 삭제코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//삽입i 탐색s 삭제d 인쇄p 종료q
typedef struct treeNode {
	int key;
	struct treeNode *parent;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode* treeBuild() {
	treeNode *root = (treeNode*)malloc(sizeof(treeNode) * 1);
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
	int key = 0;
	return root;
}
void putnode(treeNode *v) {
	free(v);
	v = NULL;
}
treeNode* leftChild(treeNode *v) {
	return v->left;
}
treeNode* rightChild(treeNode *v) {
	return v->right;
}
void invalidNodeException() {
	printf("invalid Node Exception\n");
}
//insert: 키값의 대소비교를 통해 트리상 N의 위치를 찾아서 넣기
void insertTree(treeNode *r, treeNode* n) {
	treeNode* root = r;
	if (n->key == root->key) return; //n: 루트노드일 때
	else if (n->key < root->key) { // 새 노드의 키 < 부모의 키
		if (root->left == NULL) {
			root->left = n;
			n->parent = root;
		}
		else insertTree(root->left, n);
	}
	else {
		if (root->right == NULL) {
			root->right = n;
			n->parent = root;
		}
		else insertTree(root->right, n);
	}
}
//insertItem: 새 노드 n에 key 삽입
void insertItem(treeNode *n, int key) {
	n->key = key;
	return;
}
//treeSearch: 트리 상 탐색연산(키값이 있나?) [반환값:트리노드 n]
treeNode* treeSearch(treeNode *n, int key) {
	if (n == NULL) return NULL;
	else if (key == n->key) return n;
	else if (key < n->key) return treeSearch(n->left, key);
	else return treeSearch(n->right, key);
}
int isExternal(treeNode *v) {
	return (v->left == NULL&&v->right == NULL);
}
int isInternal(treeNode *v) {
	return (v->left != NULL || v->right != NULL);
}
treeNode* inOrderSucc(treeNode* node) {
	treeNode* w = node;
	w = rightChild(w);
	while (isInternal(leftChild(w))) {
		w = leftChild(w);
	}
	return w;
}
//visit: 노드의 키 출력
void visit(treeNode* v) {
	printf(" %d", v->key);
}
//전위순회
void binaryPreOrder(treeNode* node) {
	treeNode *v = node;
	if (v != NULL) {
		visit(v);
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}
treeNode* removeNode(treeNode *root, int key) {
	//먼저 key값 찾기
	treeNode* n = root;
	treeNode* Parent = NULL;
	while ((n != NULL) && (n->key != key)) {
		Parent = n;
		if (n->key < key) n = rightChild(n);
		else n = leftChild(n);
	}
	//만약 삭제할 키값이 없다면 'X' 출력후 종료
	if (n == NULL) {
		printf("X\n");
		return root;
	}
	//case1 단말 노드 삭제
	else if (leftChild(n) == NULL && rightChild(n) == NULL) {
		if (Parent == NULL) {
			root = NULL;
		}
		else {
			if (n == leftChild(Parent)) {
				Parent->left = NULL;
			}
			else {
				Parent->right = NULL;
			}
		}
		putnode(n);
		printf("%d\n", key);
		return root;
	}
	//case2 자식이 하나인 노드 삭제
	else if (leftChild(n) == NULL || rightChild(n) == NULL) {
		treeNode* Child = (n->left != NULL) ? n->left : n->right;
		if (Parent == NULL) root = Child;
		else {
			if (Parent->left == n) Parent->left = Child;
			else Parent->right = Child;
		}
		putnode(n);
		printf("%d\n", key);
		return root;
	}
	//case3 두 개 자식을 가진 노드 삭제
	else {
		
		treeNode *Succ_parent = n;
		treeNode* Succ = n->right;
		while (Succ->left != NULL) {
			Succ_parent = Succ;
			Succ = leftChild(Succ);
		}
		n->key = Succ->key;
		if (Succ_parent->left == Succ) {
			Succ->parent->left = Succ->right;
		}
		else {
			Succ_parent->right = Succ->right;
		}
		n = Succ;
		putnode(n);
		printf("%d\n", key);
		return root;
	}
}

int main() {
	char func;
	int key;
	int is_root = 1;
	int test_num;
	treeNode *root = treeBuild();
	while (1) {
		scanf("%c", &func);
		getchar();

		if (func == 'i') {
			scanf("%d", &key);
			getchar();
			if (is_root == 1) {
				insertItem(root, key);
				is_root = 0;
			}
			else {
				treeNode *n = treeBuild();
				insertItem(n, key);
				insertTree(root, n);
			}
		}
		else if (func == 'd') {
			scanf("%d", &key);
			getchar();
			root = removeNode(root, key);
		}
		else if (func == 's') {
			scanf("%d", &key);
			getchar();
			treeNode *nn = treeSearch(root, key);
			if (nn == NULL) {
				printf("X\n");
			}
			else {
				printf("%d\n", nn->key);
			}
		}
		else if (func == 'p') {
			binaryPreOrder(root);
			printf("\n");
		}
		else if (func == 'q') break;
	}
	putnode(root);
	return 0;
}
