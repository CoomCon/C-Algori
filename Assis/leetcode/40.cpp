#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

    void dfs(vector<int> candidate,int k,int n,vector<vector<int>> &ans, vector<int> &combine,int index)
    {
        
        if(n==0&&k==0)
        {
            ans.push_back(combine);
            return;
        }
        if(index == candidate.size())
            return;

        dfs(candidate,k,n,ans,combine,index+1);
        if(n>=candidate[index] && k>=0)
        {
            combine.push_back(candidate[index]); 
            dfs(candidate,k-1,n-candidate[index],ans,combine,index+1);
            combine.pop_back();
        }

       

        

        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidate={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidate,k,n,ans,combine,0);
        return ans;
    }
};
int main()
{
    Solution so;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    so.combinationSum3(3, 15);

    return 0;
}