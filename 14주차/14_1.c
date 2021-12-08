#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#define INF   1000000
#define MAX_VTXS 100
int d[MAX_VTXS]; 
int v[MAX_VTXS]; 
int n, m, s;
int a[MAX_VTXS][MAX_VTXS];

void load_graph()
{
   int i, j;
   scanf("%d %d %d", &n, &m, &s);
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         a[i][j] = INF;
      }
   }
   getchar();
   int n1, n2, val;
   for (i = 0; i < m; i++)
   {
      scanf("%d %d %d", &n1, &n2, &val);
      a[n1 - 1][n2 - 1] = val;
      a[n2 - 1][n1 - 1] = val;
   }
}

int getsmallindex()
{
   int min = INF;
   int index = 0;
   int i;
   for (i = 0; i < n; i++) {
      if (d[i] < min && !v[i]) {
         min = d[i];
         index = i;
      }
   }
   return index;
}

void dijkstra(int start)
{
   int i;
   for (i = 0; i < n; i++)
   {
      d[i] = a[start - 1][i];
      v[i] = 0;
   }
   v[start - 1] = 1;
   for (i = 0; i < n - 1; i++)
   {
      int current = getsmallindex();
      v[current] = 1;
      for (int j = 0; j < n; j++)
      {
         if (!v[j])
         {
            if ((d[current] + a[current][j]) < d[j]) {
               d[j] = d[current] + a[current][j];
            }
         }
      }
   }
}
   
int main(void)
{
   load_graph();
   dijkstra(s);
   for (int i = 0; i < n; i++)
   {
      if (d[i] != INF) {
         printf("%d %d\n", i + 1, d[i]);
      }
   }


    return 0;
}
