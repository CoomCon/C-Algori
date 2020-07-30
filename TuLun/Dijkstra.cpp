#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;


#define N 1100
#define INF 0x3f3f3f
int map[N][N];
int d[N];
int visit[N];
int n;


// int main()
// {
//     int Node, Edge;
//     string line;
//     getline(cin, line);
//     stringstream ss(line);
//     ss >> Node;
//     ss >> Edge;

//     return 0;
// }


// int min(int a, int b)
// {
// 	if (a > b)
// 		a = b;
// 	return a;
// }

void Dijkstra(int x)//所有点到1的最短路径
{
	memset(visit, 0, sizeof(visit));
	int i, j;
	for (i = 1; i <= n; i++)
	{
		d[i] = map[x][i];
	}
	for (i = 1; i <= n; i++)
	{
		int min_cost = -1;
		int index;
		for (j = 1; j <= n; j++)
		{
			if (visit[j] == 0 && d[j] > min_cost)
			{
				min_cost = d[j];
				//	printf("%d\n",d[j]);
				index = j;
			}
		}
		visit[index] = 1;
		//	printf("%d\n\n\n",index);
		for (j = 1; j <= n; j++)
		{
			if (visit[j] == 0 && d[j] < min(map[index][j], min_cost))
			{
				d[j] = min(map[index][j], min_cost);

			}
		}
	}
	printf("%d\n\n", d[n]);      //输出最终节点与首节点之间的最小距离
}

int main()
{
	int i, j, m, k, l, u, v, w;
	int T, t = 0;
	scanf("%d", &T);     //T个测试
	while (T--)           
	{ 
		t++;             //输出例子
		scanf("%d%d", &n, &m);              //交叉口，和最大承重量。实际上就是节点和边的权重
		memset(map, 0, sizeof(map));        //清空背包
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);   //依次输入节点，节点，这两个节点之间的权重
			map[u][v] = map[v][u] = w;
		}
		printf("Scenario #%d:\n", t);
		Dijkstra(1);                    //从第几号节点开始
	}
	return 0;
}

