#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> da(n,0);
    for(int i =0;i<n;i++)
    {
        cin>>da[i];
    }
    int t;
    cin>>t;
    sort(da.begin(),da.end());
    vector<int> dp(t+1,-9999);
    dp[0] = 0;
    //dp[i][j] 还有j分钟时，播放i歌曲
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            if(j>=da[i-1])
                dp[j] =  hy6(dp[j],dp[j-da[i-1]]+da[i-1]);
        }
                
    }
    cout<<dp[t-1]+da.back()<<endl;
    cout << dp[t] << endl;
    return 0;
}