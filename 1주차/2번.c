#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treeNode {
	int id;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

int isInternal(treeNode *v) {
	return (v->left != NULL&&v->right != NULL);
}
int isExternal(treeNode *v) {
	return (v->left == NULL&&v->right == NULL);
}
treeNode* leftChild(treeNode* v) {
	return v->left;
}
treeNode* rightChild(treeNode* v) {
	return v->right;
}
treeNode* binaryPreOrder(treeNode* root) {
	treeNode *p = root;
	if (isInternal(p)) {
		binaryPreOrder(leftChild(p));
		binaryPreOrder(rightChild(p));
	}
	return p;
}
void insertNode(treeNode* v,char type,int id) {
	treeNode *p=(treeNode*)malloc(sizeof(treeNode)*1);
	p->left = NULL;
	p->right = NULL;
	p->id = id;

	if (type == 'L') {
		v->left = p;
	}
	if (type == 'R') {
		v->right = p;
	}
	else {
		return -1;
	}
}
void visit(treeNode *v) {
	printf(" %d", v->id);
}
treeNode* findID(treeNode *v, int id) {
	if (v != NULL) {
		if (v->id == id) return v;
		treeNode *p = findID(leftChild(v), id);
		if (p != NULL) return p;
		p = findID(rightChild(v), id);
		if (p != NULL) return p;
	}
	return NULL;
}
treeNode* treeBuild() {
	treeNode* root=(treeNode*)malloc(sizeof(treeNode)*1);
	root->left = NULL;
	root->right = NULL;
	
	int num;
	int id, left_id, right_id;
	int isRoot=1;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d %d %d", &id, &left_id, &right_id);

		if (isRoot == 1) { //루트 노드 설정
			root->id = id;
			if (left_id != 0) insertNode(root, 'L', left_id);
			if (right_id != 0) insertNode(root, 'R', right_id);
			isRoot = 0;
		}
		else { //노드 추가
			treeNode* newNode = findID(root, id);
			if (left_id != 0) insertNode(newNode, 'L', left_id);
			if (right_id != 0) insertNode(newNode, 'R', right_id);
		}
	}
	return root;
}
treeNode* treeSearch(treeNode *root) {
	int search, i;
	char str[101];
	
	scanf("%d", &search);	

	for (i = 0; i < search; i++) {
		scanf("%s", str);
		treeNode* p = root;
		visit(p);
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == 'L') p = leftChild(p);
			else if (str[j] == 'R') p = rightChild(p);
			visit(p);
		}
		printf("\n");
	}
}
int main() {
	treeNode* root=treeBuild();

	treeSearch(root);

	return 0;
}
