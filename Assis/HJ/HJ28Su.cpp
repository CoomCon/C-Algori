#include<iostream>
#include <vector>
#include <string>
#include<sstream>
#include <cmath>
using namespace std;

//判断素数
bool isSu(int a)
{
    if(a<4)
        return true;
    //for (int i = 3; i < a / 2; i++) //i< pow(a,0.5);
    for (int i = 3; i < sqrt(a); i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}

bool process(int jn,vector<int> &ou,vector<int> &vist,vector<int> &girl)
{
    for (int ji = 0; ji < ou.size();ji++) //扫描所有右边的数
    {
        if(isSu(jn+ou[ji]) && vist[ji]==0) //如果和是素数，而且左边未被访问过
        {
            vist[ji] = 1;
            if(girl[ji] == 0 || process(girl[ji],ou,vist,girl)) //如果右边未被访问过，获得可以腾出位置来
            {
                girl[ji] = jn; //索引为j的偶数对应的奇数
                return true;
            }
        }
    }      
    return false;
}

int main()
{
    int n;
    vector<int> dataji,dataou;
    cin >> n;
    string str;
    getline(cin, str);
    getline(cin, str);
    stringstream ss(str);
    int temp;
    for (int i = 0; i < n; i++)
    {
        ss >> temp;
        if(temp%2==0)
        //隔这儿分组
            dataou.push_back(temp); 
        else
            dataji.push_back(temp);
    }
    
    //int res = process(data,iteri,iteri,true);
    vector<int> visitedJi(dataji.size(), 0); //左边和右边的使用标记
    vector<int> visitedOu(dataou.size(), 0);//奇数在左边，偶数在右边
    if(dataji.size()==0&&dataou.size()==0)
        return 0;
    //
    int res = 0;
    for (int i = 0; i < dataji.size();i++)
    {
        if(process(dataji[i],dataou,visitedOu,visitedJi)) //(左列一点，右列全部，左列访问数组，右列与左列的连接)
            res++;
    }
    cout << res << endl;

    return 0;
}


