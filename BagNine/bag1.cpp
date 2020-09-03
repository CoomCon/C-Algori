#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

const int N = 1010;
// 全局变量 定义到堆里面 堆里面会自动初始化为0
//const int N = 1000;
int f[N][N];
int v[N], w[N];

int main()
{
    int n, m;
    
    cin >> n >> m;
    f[0][0] = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            f[i][j] = f[i - 1][j];
            if(j>= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }

    return f[n][m];
    //vector<int> data = vector<int>(n,0)
}