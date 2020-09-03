/*
第二题，牛牛走地图n*m，地图每一块都有个标志，C或S，陆地或者海洋，陆地之间穿梭是消耗2点体力值，海洋之间穿梭是3体力值，陆地海洋之间是（忘记几了，反正是一个数），问从起点到终点最少消耗多少体力值。
输入 每次只能上下左右
n，m，q
下面是地图块的标志。例如:
cssssccc
sssscccc
sssccccs
下面是q行询问，
比如：
1 1 3 4（表示从（1,1）到（3,4），问我们最少需要体力值）

4 4 2
CCCS
SSSS
CSCS
SSCC
1 1 3 4
3 1 1 3 
*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int bx, by,ex,ey;
int res=9999,cur=0;
int dire[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visit[4][4] = {false};
//
void dfs(int x, int y)
{
    //dfs
    if(cur>=res)
        return;
    if(x==ex && y==ey)
    {
        if(cur < res)
            res = cur;
        return;
    }

    
    for (int i = 0; i < 4;i++)
    {
        int nextX = x + dire[i][0];
        int nextY = y + dire[i][1];
        if( nextX>=0 && nextX<4 && nextX>=0 && nextX<4 && !visit[x][y])//点合不合适
        {
            int add = 2;
            if()
                add = 3;
            else if()
            {
                add = 5;
            }
            cur += add;
            visit[x][y] = true;
            dfs(nextX, nextY);
            //上面dfs走不下去
            cur -= add;
            visit[x][y] = false;
            //继续循环换下一个方向
        }
    
    }
}

int main()
{
    int n, m, q;
    vector<vector<int>> data(n, vector<int>(m, 0));


}