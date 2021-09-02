#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000
int selected[101];
int dist[101];
int sum = 0;
int vsize;
typedef struct graph
{
	int vertexnum;
	int** matrix;
} Graph;

Graph* graph;
Graph* Newgraph(int max_vertex){
	int i, j;
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->vertexnum = max_vertex;
	graph->matrix = (int**)malloc(sizeof(int*) * (max_vertex));
	for (i = 0; i < max_vertex; i++)
	{
		graph->matrix[i] = (int*)malloc(sizeof(int) * (max_vertex));

		for (j = 0; j < max_vertex; j++)
		{
			graph->matrix[i][j] = 1000;
		}
	}
	return graph;
}
void addEdge(int start, int goal, int weigh)
{
	graph->matrix[start - 1][goal - 1] = weigh;
	graph->matrix[goal - 1][start - 1] = weigh;
}
void ViewNeighbor(int vt){
	int i;
	for (i = 1; i <= graph->vertexnum; i++)
	{
		if (graph->matrix[vt - 1][i - 1] >= 0)
		{
			printf("%d ", graph->matrix[vt - 1][i - 1]);
		}
	}
}
void Correctgraph(int v1, int v2, int weigh) {
	if (weigh == 0)
	{
		graph->matrix[v1 - 1][v2 - 1] = -1;
		graph->matrix[v2 - 1][v1 - 1] = -1;
	}
	else
	{
		graph->matrix[v1 - 1][v2 - 1] = weigh;
		graph->matrix[v2 - 1][v1 - 1] = weigh;
	}
}

int getMinVertex()
{
	int v, minv = 0, mindist = INF;
	for (v = 0; v < vsize; v++)
		if (selected[v] != 1 && dist[v] < mindist)
		{
			mindist = dist[v];
			minv = v;
		}

	sum = sum + mindist;

	return minv;
}

// Prim
void Prim()
{
	int i, u, v;

	for (i = 0; i < vsize; i++)
	{
		dist[i] = INF;
		selected[i] = 0;
	}

	dist[0] = 0;

	for (i = 0; i < vsize; i++)
	{
		u = getMinVertex();
		selected[u] = 1;
		if (dist[u] == INF)
			return;
		printf(" %d", u + 1);

		for (v = 0; v < vsize; v++)
			if (graph->matrix[u][v] != INF)
				if (selected[v] != 1 && graph->matrix[u][v] < dist[v])
					dist[v] = graph->matrix[u][v];
	}
	printf("\n");
}

int main()
{
	int v1, v2, w;
	int i;
	int n, m;
	scanf("%d %d", &n, &m);
	vsize = n;

	graph = Newgraph(n);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &v1, &v2, &w);
		addEdge(v1, v2, w);
		addEdge(v2, v1, w);
	}

	Prim();

	printf("%d", sum);

	return 0;
}
