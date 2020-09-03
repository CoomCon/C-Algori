#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

//华为笔试题0715

int main()
{
    vector<int> coins = {1, 3, 7, 11, 13};
    vector<int> nums = {1,2,3,4,5};
    int m = 30;

    //多维背包问题 --- 二进制优化
    vector<int> v, w;
    for (int i = 0; i <= coins.size(); i++)
    {
        for (int k = 1; k <= nums[i];k*=2)
        {
            v.push_back(k * coins[i]);
            w.push_back(k); //个数也要统计

            nums[i] -= k;
        }
        if(nums[i]>0)
        {
            v.push_back(nums[i] * coins[i]);
            w.push_back(nums[i]);
        }
    }

    vector<int> f(m + 1, 1);
    f[0] = 1;
    for (int i = 0; i < v.size();i++)
    {
        for (int j = m; j >= v[i];j--)
        {
            f[j] = (f[j]+ f[j - v[i]] + w[i]);
        }
    }

    if(f[m] == 9999)
        cout << -1 << endl;
    cout << f[m] << endl;

    return 0;
}




// int main()
// {
//     vector<int> coins = {2};
//     int amount = 3;
//     int m = amount;
//     vector<int> f(amount + 1, 99999);//初始化为-1 没有答案就需要用-1输出
//     f[0] = 0;
//     for (int i = coins.size(); i > 0;i--) //循环coins 和 循环amount 先后没有区别
//     {
//         for (int j = 1; j <= m ;j++)
//         {
//             if( j>=coins[i-1])
//                 f[j] = min(f[j], f[j - coins[i-1]] + 1);
//         }
//     }

//     return f[m];
//     //vector<int> data = vector<int>(n,0)
// }