#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k;
    vector<int> dn,dm;
    int tmpn,tmpm;
    for(int i=0;i<k;i++)
    {
        cin>>tmpn>>tmpm;
        dn.push_back(tmpn);
        dm.push_back(tmpm);
        if(tmpn == tmpm)
        {
            cout<<tmpm<<endl;
            return 0;
        }
    }
    
    if(dn.size()==0 || dm.size()==0)
           cout<<0<<endl;
    //进制问题；
    //n进制；
    if(dn.size()!=dm.size())
           cout<<0<<endl;
    vector<int> ans;
    int tempans;
    cout<<0<<endl;
    
    
    
}