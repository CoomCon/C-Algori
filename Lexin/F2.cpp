#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        long long ans = 0;
        for(int i=n-1;i>=0;i-=2)
        {
            ans += pow(2,i-1);
        }
        cout<<ans<<endl;
    }
     
    
    
    
    
    
}