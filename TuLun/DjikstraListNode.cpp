#include<iostream>
#include <vector>

using namespace std;
//邻接表表示迪杰特斯拉

#define NUMN 5 //定点个数
#define INF 0xFFFFFFFF
typedef struct ListNode
{
    int index;
    int weight;
    ListNode *next;
    ListNode(int i, int c) : index(x), weight(c),  next(NULL)){}
} *pListNode, ListNode;

int Dijkstra(int s,int e,vector<pListNode> plist)
{
    int dis[NUMN] = INF;
    int pre[NUMN] = -1;
    bool visit[NUMN] = false;


    
}
int main()
{
    vector<pListNode> plist(5);



}