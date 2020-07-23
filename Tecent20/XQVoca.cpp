#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int process(int N,vector<int>  data1, vector<int> data2)
{
    //int ans = (int)malloc(sizeof(int) * N);
    //dp[0][i], dp[1][i], 
    //dp[2][i]分别代表第i天休息最少休息天数、
    //第i天工作最少休息天数、第i天健身最少休息天数
    // dp[0][i] = min(dp[0][i-1], dp[1][i-1], dp[2][i-1]) + 1 $
    vector<vector<int>> dp(3, vector<int>(N)); //3 x N
    dp[0][0] = 1;
    if(data1[0]==1)
        dp[1][0] = 0;
    else
        dp[1][0] = N + 1;//
    if(data2[0]==1) 
        dp[2][0] = 0;
    else
        dp[2][0] = N + 1;

    
        

    for (int i = 1; i < N;i++)
    {
        dp[0][i] = min(dp[0][i - 1], min(dp[1][i - 1], dp[2][i - 1])) + 1;

        if(data1[i]==1) //今天工作 昨天不可以工作
        {
            dp[1][i] = min(dp[0][i - 1],dp[2][i - 1]);
        }else
        {
            dp[1][i] = N+1;
        }
        
        if(data2[i]==1)
        {
            dp[2][i] = min(dp[0][i - 1],dp[1][i - 1]);
        }else
        {
            dp[2][i] = N+1;
        }
    }
    return min(dp[0][N-1],min( dp[1][N-1], dp[2][N-1]));
}

int main()
{
    int N;
    cin >> N;
    string line1;
    getline(cin, line1);//吸收回车键
    getline(cin, line1);
    string line2;
    getline(cin, line2);
    vector<int> data1, data2;
    stringstream ss1(line1),ss2(line2);
    for (int i = 0; i < N;i++)
    {
        int temp;
        ss1 >> temp;
        data1.push_back(temp);
        ss2 >> temp;
        data2.push_back(temp);
    }

    int ans = process(N, data1, data2);
    cout << ans << endl;
    
    return 0;
}