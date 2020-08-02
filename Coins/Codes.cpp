#include <iostream>
#include <vector>
using namespace std;
//动规+记忆搜索

//自下而上
int dp(vector<int> &coins,int amount)
{
    coins.erase(0);
}
int findcoins2(vector<int> &coins,int amount)
{ 
     if(amount<0)
         return -1;
     return dp(coins, amount);
}
//自下而上的动规
 int findcoins(vector<int> &coins,int amount)
 {

     vector<int> dp(amount + 1,9999);
     dp[0] = 0;
     for (int i = 0; i <= amount;i++)
     {
         for (int j = 0; j < coins.size();j++)
         {
             if(i>=coins[j])
             {
                 dp[i] = min(dp[i], dp[i - coins[j]] + 1); //INTMAX+1会越界变为负数
             }
         }
     }

     return dp[amount] > amount ? -1 : dp[amount];
 }


int main()
{
    vector<int> a = {2,3};
    int b = 3;
    int num[4] = {0};
    int res = findcoins(a, b);

    //贪心
    for (int i = 3; i >= 0;i--)
    {
        num[i]= b / a[i];
        b -= num[i] * a[i];
    }
    //贪心+回溯
    return 0;
    ///


}