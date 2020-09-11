#include<iostream>
#include <vector>
//#include <math.h>
#include <cmath>

using namespace std;

/*
功能: 求出n以内的自守数的个数


输入参数：
int n

返回值：
n以内自守数的数量。
*/


int CalcAutomorphicNumbers( int n)
{
/*在这里实现功能*/
    //0 1 算 2
    int res=0;
    for(int i=2;i<=n;i++)
    {
       if((i*i-i)% (int)pow(10,calcW(i)) == 0)
       {
           res++;
       }
    }
    return 2+res;
}

int calcW(int n)
{
    vector<int> nv;
    while(n!=0)
    {
        nv.push_back(n%10);//逆序
        n/=10;
    }
    return nv.size();
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<CalcAutomorphicNumbers( n)<<endl;    
    }
    return 0;
}