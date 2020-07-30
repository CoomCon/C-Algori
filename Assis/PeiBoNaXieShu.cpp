#include <iostream>
#include <vector>
using namespace std;

int pos(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return pos(n - 1) + pos(n - 2);
}

int posmemo(vector<int> memo,int n)
{
    if(n==1||n==2)
    {
        return 1;
    }
           
    if(memo[n] != 0)
        return memo[n];
    memo[n] = posmemo(memo,n - 1) + posmemo(memo,n - 2);

    return memo[n];
}

int main()
{
    
    int n;
    cin >> n;
    vector<int> memo(n + 1, 0);
    memo[1] = 1;
    memo[2] = 1;
    cout << posmemo(memo,n) << endl;
    system("pause");
}