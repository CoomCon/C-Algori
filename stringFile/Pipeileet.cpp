#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N+1);
        if(N==1)
            return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        int j=2;
        while(j<N)
        {
            dp[j] = max(dp[j-1],nums[j]+dp[j-2]);
            j++;
        }
        return dp[N-1];
    }
};


int main()
{
    vector<int> a = {1, 2, 3, 1,4,4,2,2,5,6,6,7,8,99,2};
    Solution so;
    cout << so.rob(a) << endl;
    
}