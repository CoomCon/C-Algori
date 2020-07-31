#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;


#define N 5
#define INF 0x3f3f3f

int dis[N];
bool visit[N];
int pre[N];

// void Dijkstra(int s) //建表过程 ,建立图中所有点与s的最短路径
int Dijkstra(int s,int e,int map[N][N])//s->e的最短路径
{
	memset(visit, false, sizeof(visit));
	memset(dis, INF, sizeof(dis));
	memset(pre, -1, sizeof(pre));

	dis[s] = 0;

	for (int i = 0; i < N; i++)
	{
		dis[i] = map[s][i];
		pre[i] = s;
	}
	//

	//建表操作
	for (int i = 0; i < N; i++)
	{
		int distemp = INF;
		int indextemp;
		//找一个最近点 遍历所有点
		for (int j = 0; j < N; j++)
		{
			if ( !visit[j] && dis[j] < distemp)
			{
				distemp = dis[j];
				
				indextemp = j;
			}
		}
		visit[indextemp] = true; //标记访问过

		//	第二次遍历 目的是优化
		for (int j = 0; j < N; j++) 
		{
			if (!visit[j] && dis[j] > map[indextemp][j] + distemp) //言外一直 a->d的直接距离 大于 a->index->d
			{
				dis[j] = map[indextemp][j] + distemp;
				pre[j] = indextemp;//前驱点更新 
			}
		}
	}
	//所有遍历完，表就建好了，有用的主要是前驱表pre[]和距离表dis[]
	return dis[e];
}

void prin(int i,int s)
{
	cout << pre[i] << "<-";
	if(pre[i]!=s)
		prin(pre[i],s);
}
int main()
{
	int map[5][5] =
		{
			{0, 6, INF, 1, INF}, //不直接相连的点距离就是无穷大
			{6, 0, 5, 2, 2},
			{INF, 5, 0, 5, INF},
			{1, 2, INF, 0, 1},
			{INF, 2, 5, 1, 0},
		};

	int res = Dijkstra(0,2,map); 

	cout << res << endl;

	cout << "2";
	prin(2,0);
	return 0;
}

