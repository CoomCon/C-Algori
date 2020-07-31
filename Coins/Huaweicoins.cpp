#include <iostream>
#include <vector>
using namespace std;


int findcoins(vector<int> coins,vector<int> nums,int amount)
{
    vector<int> dp(amount + 1, 99999); //初始化为num中最大的一个就可
    dp[0] = 0;
    for (int i = 1; i <= amount;i++)
    {
        for (int j = 0; j < coins.size();j++)
        {
            if(nums[j]>0 && i >= coins[j])
            {
                if((dp[i - coins[j]] + 1) < dp[i])
                {
                    nums[j]--; //--有问题
                    dp[i]=dp[i - coins[j]] + 1;
                }
               //else dp[i] = dp[i]
            }
                
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];//与amount的比对使用的正的金钱
}



int main()
{
    vector<int> price = {1, 3, 7, 11, 13};
    vector<int> nums = {1, 2, 3, 4, 5};
    int amount = 30;

    int res = findcoins(price, nums, amount);

    return 0;
}