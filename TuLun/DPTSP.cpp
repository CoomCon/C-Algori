#include <iostream>
#include <vector>
using namespace std;
#define TMAX 99999;


int DpTSP(G)
{
    int res = TMAX;
    int Hvol = 1 << G.size();
    vector<vector<int>> dp(4,vector<int>(4,Hvol));

    //自下而上
    dp[1][0] = G[1][0];
    dp[2][0] = G[2][0];
    dp[3][0] = G[3][0];
    
    for (int i = 0; i < Hvol;i<<1)
    {
        dp[0]
    }
         dp[][]

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