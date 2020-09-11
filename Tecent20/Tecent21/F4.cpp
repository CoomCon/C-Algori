#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const pair<char,int>  &x, const pair<char,int> &y)
{
    if(x.second == y.second)
        return x.first < y.first;
    return x.second > y.second;
}

bool comp2(const pair<char,int>  &x, const pair<char,int> &y)
{
    return x.second < y.second;
}
int main()
{
    int N,K;
    cin>>N>>K;
    map<char,int> data;
    for(int i=0;i<N;i++)
    {
        char tep;
        cin>>tep;
        if(data.count(tep)!=0)
        {
            data.find(tep)->second++;
        }else
        {
            data.insert(make_pair(tep, 1));
        }
    }
    vector<pair<char,int> > ans;
    for (map<char, int>::iterator ite = data.begin(); ite != data.end(); ite++)
    {
        ans.push_back(make_pair(ite->first, ite->second));
    }
    

    sort(ans.begin(), ans.end(), comp);
    vector<pair<char, int>>::iterator iter = ans.begin();
    for (int i = 0; i < K;i++)
    {
        cout << iter->first << " " << iter->second << endl;
        iter++;
    }
    iter = ans.end();
    for(int i = ans.size()-K; i < ans.size();i++)
    {
        //char tmp = ans[i].first;
        cout << ans[i].first << " " << ans[i].second << endl;
        //iter++;
    }
/*
    sort(ans.begin(), ans.end(), comp2);
    iter = ans.begin();
    for (int i = 0; i < K;i++)
    {
        cout << iter->first << " " << iter->second << endl;
        iter++;
    }*/
        /*multimap<int,char> ans;
    for (map<char, int>::iterator ite = data.begin(); ite != data.end(); ite++)
    {
        ans.insert(make_pair(ite->second, ite->first));
    }
     multimap<int,char> ::iterator itestart = ans.begin();
     multimap<int,char> ::iterator iteend = ans.end();

    
    for (int i = 0; i < K;i++)
    {
        iteend--;
        cout << iteend->second << " " << iteend->first << endl;
        
    }

    for (int i = 0; i < K;i++)
    {
        
        itestart++;
    }
    for (int i = 0; i < K;i++)
    {
        cout << itestart->second << " " << itestart->first << endl;
        itestart--;
    }
*/
        return 0;
}