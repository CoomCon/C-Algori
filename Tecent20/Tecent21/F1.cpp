#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> data(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    int m;
    vector<int> data2(m,0);
    vector<int> ans;
    int lastj = 0;
    for(int i=0;i<m;i++)
    {
        cin>>data2[i];
        for(int j=lastj;j<n;j++)
        {
            if(data[j]==data2[i])
            {
                ans.push_back(data[j]);
                cout<<data[j]<<" ";
                //lastj++
                lastj++;
            }else if(data[j]>data2[i])
            {
                ;
            }else if(data[j]<data2[i])
            {
                break;
            }
        }
    }
    
    return 0;
    
}