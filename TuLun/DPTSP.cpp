#include <iostream>
#include <vector>
using namespace std;
#define TMAX 99999;


void DSP(vector<vector<int>> &dp,int s,int V, vector<vector<int>> &G)
{
    if(V == 0)
    {
        dp[1][0] = G[1][0];
        dp[2][0] = G[2][0];
        dp[3][0] = G[3][0]; 
    }
    else{
        while(V>>1 != 0)
        {
            dp[0][Hvol] = min(

            );
        }
    }
    dp[]

}


int DpTSP(vector<vector<int>> &G,int N)
{
    int res = TMAX;
    int Hvol = 1 << G.size(); //4个点 就是8
    vector<vector<int>> dp(4,vector<int>(Hvol,TMAX));

    //自下而上
    dp[0][0] = G[0][0];
    dp[1][0] = G[1][0];
    dp[2][0] = G[2][0];
    dp[3][0] = G[3][0];

    for (int i = 0; i < Hvol;i++) //遍历所有
    {
        for (int j = 0; j < N;j++)
        {
            dp[][]
        }
    }
         

}



int main()
{
/**动态规划模型构造
 * 对于4个城市的情况
城市的邻接矩阵如下：
        S0  S1  S2  S3  
   S0   0   3    6     7
   S1   5   0    2     7   
   S2   6   6   0     2
   S3   3   3    5     0
*/
    vector<vector<int>> G(4, vector<int>(4));
    G[0][0] = 0;
    G[0][1] = 3;
    G[0][2] = 6;
    G[0][3] = 7;
    G[1][0] = 5;
    G[1][1] = 0;
    G[1][2] = 2;
    G[1][3] = 7;
    G[2][0] = 6;
    G[2][1] = 6;
    G[2][2] = 0;
    G[2][3] = 2;
    G[3][0] = 3;
    G[3][1] = 3;
    G[3][2] = 5;
    G[3][3] = 0;

    int res = DpTSP(G);
    cout << res << endl;
}