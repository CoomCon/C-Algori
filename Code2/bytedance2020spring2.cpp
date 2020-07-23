#include <iostream>
#include<string>
#include <sstream>
#include <vector>
using namespace std;

int process(int N,int  D,vector<int> data);
int C(int length,int  temp);
int main()
{
    int N, D;
    string temp1;
    //在C++中读取一行的getline函数是不读入换行符的，而gcc / g++ 中getline函数是读入换行符的
    getline(cin, temp1);
    stringstream ss(temp1);
    ss >> N;
    ss >> D;
    //getline(cin, temp1);//接受回车键
    string datatmp;
    getline(cin, datatmp);
    vector<int> data;
    stringstream sss(datatmp);
    //while(sss) //g++读入回车键
    int i = 0;
    while (i<N)
    {
        int temp;
        sss >> temp;
        //cout << temp;
        i++;
        data.push_back(temp);
    }
    cout << process(N, D, data) << endl;

    return 0;
}

int process(int N,int  D,vector<int> data)
{
    int res=0;
    for (int i = 0;i<data.size()-2;i++) //three poi
    {
        int j = i+1;
        for (; j < data.size();j++)
        {
            if(data[j]-data[i]>D)
                break;
        }
        res += C(j - i-1, 2) % 99997867;
        // (a+b)% p =  (a%p + b%p) %p
    }
        
    return res % 99997867;
}
//组合
int C(int length,int  temp)
{
    if(length <= 0 || length < temp)
        return 0;
    if(length == temp)
        return 1;
    int res = 1;
    for (int ik = 0; ik<temp;ik++) //C(6,2) = 15
    {
        res *= length-ik;
    }
    for (int it = temp; it > 1;it--)
    {
        res /= it;
    }

        return res;
}