#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;


int main()
{
    string strl;
    getline(cin, strl);
    int K;
    cin >> K;
    //vector<int> data;
    map<int, int> idnex;
    for (int i = 0; i < strl.size();i++)
    {
        int temp = strl[i] - '0';
        if(idnex.count(temp) ==0)//如果不存在
            idnex.insert(make_pair(temp, i));
        //data.push_back(temp);
    }
    map<int, int>::iterator iter = idnex.end();
    for (int i = 0; i < K;i++,iter--)
    {
        strl =  strl.substr(iter->second, 1);
    }
    cout << strl << endl;
    // process


}