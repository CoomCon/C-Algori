#include <iostream>
#include <vector>

using namespace std;

int dp(int v)
{
    if(v==0)
        return 0;
    if(v==1)
        return 1;
    if(v==2)
        return 2;

    return dp(v - 1) + dp( v - 2) + dp( v - 3); //会有大量重复运算  可以加入一个help
}


int main()
{
    //代码题：一百个台阶，
    //分一步，两步，三步，三种上法，
    //一共有多少种可能性。 
    //f(n) = f(n-1) + f(n-2) + f(n-3) 
    vector<int> a = {1, 2, 3};
    //完全背包问题
    //容量为台阶总数
    //
    int v = 100;
    vector<int> f(v + 1, 0);
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 100;i++)
    {
        //在某一位置处，前面一步 一定选择走1 2 3 步其中一个 就三种可能；
        f[i] = f[i - 3] + f[i - 2] + f[i - 1];
    }
        int da = dp(5);

    /*
        for (int j = 1; j <= v;j++)
        {
             for (int i = 0; i < a.size();i++)
    {
            if(j>=a[i])
            {
                //f[j] = max(f[j], f[j - a[i]] + 1);
                f[j] = f[j]+ (f[j - a[i]] + 1);
            }
        }
    }
*/
    cout << f[5] << endl;
}