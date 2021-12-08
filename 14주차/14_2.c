#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#define INF   100000
#define MAX_VTXS 256
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
   }
}


void dijkstra(int start)
{
   int i, j;
   int k;
   for (i = 0; i < n; i++)
   {
      d[i] = INF;
   }
   d[s - 1] = 0;
   for (k = 0; k < n; k++)
   {
      for (i = 0; i < n; i++)
      {
         for (j = 0; j < n; j++)
         {
            if (d[i] != INF && d[j] > d[i] + a[i][j])
            {
               d[j] = d[i] + a[i][j];
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
      if (d[i] < INF - 500 && i + 1 != s) {
         printf("%d %d\n", i + 1, d[i]);
      }
   }


    return 0;
}
