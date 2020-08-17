#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


// bool cmp(const pair<string,int> &p1,const pair<string,int> &p2)//要用常数，不然编译错误 
// {
// 	return p1.second<p2.second;
// }


int main()
{
    map<char,int> data;
    string str;
    getline(cin,str);
    map<char, int>::iterator iter;
    vector<int> index;
    for(int i=0;i<str.size();i++)
    {
        if(isalnum(str[i])||str[i] == ' ')
        {
            if(data.count(str[i])) //找到了
            {
                iter = data.find(str[i]);
                iter->second++;
            }
            else
                data.insert(make_pair(str[i], 1));
            //
            
        }
    }

    //for (map<char, int>::iterator iter = data.begin();iter!=)
     //   int res = data2.count(str[0]);
    vector< pair<char, int> > dd;
    for (map<char, int>::iterator iter = data.begin(); iter != data.end();iter++)
    {
        dd.push_back( make_pair ( iter->first, iter->second) );
    }

    //sort(dd.begin(), dd.end(), cmp);

    for (vector<pair<char, int>>::iterator iter2 = dd.begin(); iter2 != dd.end();iter2++)
    {
        cout << iter2->first << "";
    }
    cout << endl;
}