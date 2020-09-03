#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        int s = 1;
        vector< vector< vector<int> > > dp(n+1,vector< vector<int> >(k+1, vector<int>(s+1,0)));

        dp[0][0][1] = -9999999;
        dp[0][0][0] = 0;
        for(int i=0;i<=k;i++)
        {
            dp[0][i][0] = 0;
            dp[0][i][1] = -99999999;
        }

        for(int i=1;i<=n;i++)
        {
            //for(int j=0;j<=k;j++)
            for (int j = k;j>=0;j--)
            {
                for(int l = 0;l<=s;l++)
                {
                    if(l==0)
                        dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1]+prices[i-1]);
                    else if(j-1>=0)
                        dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i-1]);
                }
            }
        }

        return dp[n][k][0];



    }
};

int main()
{
    Solution so;
    vector<int> prices{12, 3, 2, 3, 5, 2, 1, 2};
    so.maxProfit(prices);
    return 0;
}