#include <stdio.h>

#include <stdlib.h>

int const maxint = 10000000;

void Dijkstra(int n, int v, int * dist, int *prev, int **c)

{

         //建立保存已找到最近的节点

         bool *s;

         s = (bool *) malloc(sizeof(bool) * (n+1));

         //循环初始化原点到各边的距离

         for(int i = 1; i <= n; i++)

         {

                   dist[i] = c[v][i];

                   s[i] = false;

                   if(dist[i] == -1)

                            prev[i] = 0;

                   else

                            prev[i] = v;

         }

         dist[v] = 0;

         s[v] = true;

       for(int o = 1; o <= n; o++)

         {

                   //设置最大值为

                   int temp = maxint;

                   //默认为原点

                   int u = v;

                   //循环，不断从dist中找出距离原点最近的节点，记录到s[]中。

                   for(int j = 1; j <= n; j++)

                   {

                            if(!s[j] && (dist[j] != -1) && (dist[j] < temp))

                            {

                                     u = j;

                                     temp = dist[j];

                            }    

                   }

                   //将其加入已找到的最短距离的数组中

                   s[u] = true;

                  

                   //修改dist[]里面的值，根据贪心性质，记录到余下节点的最短的值

                   for(int k = 1; k <= n; k++)

                   {

                            if(!s[k] && (c[u][k] != -1))

                            {

                                     int newdist = dist[u] + c[u][k];

                                     //修改原点到个边的距离

                                     if( (newdist < dist[k]) || dist[k] == -1 )

                                     {

                                               dist[k] = newdist;

                                               prev[k] = u;

                                     }

                            }

                   }

         }

}

int main(void)

{

         //顶点的个数

         int n;

         scanf("%d", &n);

         //分配数组空间

         int ** c;

         c = (int **)malloc(sizeof(int) * (n+1));

         //分配记录最短距离数组

         int * dist;

         dist = (int *) malloc(sizeof(int) * (n+1));

         dist[0] = -1;

         //分配记录前驱数组

         int * prev;

         prev = (int *) malloc(sizeof(int) * (n+1));

         prev[0] = -1;

         //矩阵,从下标1开始

         for(int i = 1; i <= n; i++)

         {

                   c[i] = (int *)malloc(sizeof(int) * (n+1));

                   c[i][0] = -1;

         }

         //读取矩阵数据

         for(int j = 1; j <= n; j++)

         {

                   for(int k = 1; k <= n; k++)

                   {

                            scanf("%d", &c[j][k]);

                   }

         }

         //执行Dijkstra算法

         Dijkstra(n, 1, dist, prev, c);

         //回归输出结果

         for(int k = 2; k <= n; k++)

         {

                   printf("1-%d:%d\n", k, dist[k]);

         }

         return 0;

}