#define _CRT_SECURE_NO_WARNINGS
#define MAX_VTXS   256
#define INF   1000
#define MAX_HEAP_NODE   100
#include <stdio.h>
#include <stdlib.h>

int cnt = 0;
int parent[MAX_VTXS];       
int set_size;            
int vsize, m;
int adj[MAX_VTXS][MAX_VTXS];
int vdata[MAX_VTXS];
void loat_graph()
{
	int n1, n2, weight;
	scanf("%d %d", &vsize, &m);
	getchar();
	int i, j;
	for (i = 0; i < vsize; i++)
	{
		for (j = 0; j < vsize; j++) {
			adj[i][j] = INF;
		}
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &n1, &n2, &weight);
		getchar();
		adj[n1 - 1][n2 - 1] = weight;
		adj[n2 - 1][n1 - 1] = weight;
	}
}
void init_set(int nSets)
{
	int i;
	set_size = nSets;
	for (i = 0; i < nSets; i++)
		parent[i] = -1;         //
}
int find_set(int id)
{
	while (parent[id] >= 0) id = parent[id];
	return id;
}
void union_set(int s1, int s2)
{
	parent[s1] = s2;
	set_size--;
}// 

typedef struct HNode {            //  
	int      key;
	int      v1;// 간선 2개
	int      v2;// 간선 2개
} HNode;

HNode heap[MAX_HEAP_NODE];
int heap_size;

#define Parent(i) (heap[i/2])      // 
#define Left(i) (heap[i*2])      //  
#define Right(i) (heap[i*2+1])   // 
#define key(n) (n.key)
void insert_heap(HNode n)
{
	//heap
	int i;
	i = ++(heap_size);
	while (i != 1 && key(n) < key(Parent(i))) {
		heap[i] = Parent(i);
		i = i / 2;
	}
	heap[i] = n;
}

HNode delete_heap()
{
	//heap
	HNode hroot, last;
	int parent = 1, child = 2;
	hroot = heap[1];
	last = heap[heap_size--];
	while (child <= heap_size)
	{
		if (child<heap_size && (key(Left(parent))>key(Right(parent))))
			child++;
		if (key(last) <= key(heap[child]))
			break;
		heap[parent] = heap[child];
		parent = child;
		child = child * 2;
	}
	heap[parent] = last;
	return hroot;
}

void init_heap() { heap_size = 0; }


void Kruskal()
{
	int i, j, edgeAccepted = 0, uset, vset;
	HNode e;

	init_heap();
	init_set(vsize);

	for (i = 0; i < vsize - 1; i++)
		for (j = i + 1; j < vsize; j++)
			if (adj[i][j] < INF) {
				e.key = adj[i][j];
				e.v1 = i;
				e.v2 = j;
				insert_heap(e);
			}

	while (edgeAccepted < vsize - 1) {
		e = delete_heap();
		uset = find_set(e.v1);
		vset = find_set(e.v2);

		if (uset != vset) {
			cnt += key(e);
			printf(" %d", e.key);
			union_set(uset, vset);
			edgeAccepted++;
		}
	}
}
void main()
{
	int i;
	for (i = 0; i < vsize; i++)	{
		vdata[i] = i + 1;
	}
	loat_graph();
	Kruskal();
	printf("\n%d", cnt);
}
