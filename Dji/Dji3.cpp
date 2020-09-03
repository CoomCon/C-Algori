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
    //依次比较相邻两位 左边大就删掉 
    // 如果不够的话，剩下的就删掉末尾的几个
    int i = 0;
    for (; i < strl.size()||K>=0;K--)
    {
        if (strl[i]>strl[i+1] )
        {
            strl.erase(i, 1);
            i--;
        }else
        {
            i++;
                }
    }
    // process


}