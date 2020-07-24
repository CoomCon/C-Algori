#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

//快速幂
int poww(int a, int b){ // return a ^ b
    int ans = 1, base = a;
    while(b != 0){
        if(b&1 != 0)  //与 运算
            ans *= base;
        base *= base;
        b>>=1; //右移就是除以2
    }
    return ans;
}

// #define MAX 1000000
// int nbit;
// int ans[MAX];


// void init(){
//     nbit = 1;
//     ans[0] = 1;
// }
 
vector<int> ans; 
// 大数幂 的基础 大数乘法
void mul(int num){
    int temp_add = 0;
    int temp_mul = 0;
    for(int i = 0; i < ans.size(); i++){
        temp_mul = num * ans[i];
        ans[i] = (temp_mul + temp_add) % 10;
        temp_add = (temp_mul + temp_add) / 10;
    }
    while(temp_add){
        ans.push_back( temp_add % 10);
        temp_add /= 10;
    }
}

// int Dsmod(int b,int num,int modnum){
//     int tempb = b % modnum;
//     for(int i = 1; i < num; i++)
//         tempb = tempb * tempb % modnum;
//     return tempb;

// }

void init(int b)
{
    ans.clear();
    while(b>0)
    {
        ans.push_back(b % 10); //倒序
        b /= 10;
    }
}

vector<int> powd(int b, int e){
    init(b);
    for(int i = 1; i < e; i++) 
        mul(b);
    return ans;
}


vector<int> allo(int b){
    vector<int> res;
    while(b>0)
    {
        res.push_back(b % 10); //倒序
        b /= 10;
    }
    return res;
}
//检查是否是相等
bool check(vector<int> a,vector<int> b)
{
    //可以用堆栈来检查
  
    for (vector<int>::iterator iter = b.begin(); iter != b.end();) //itereate
        {
            for (vector<int>::iterator iter2 = a.begin(); iter2 != a.end();)
            {
            if (*iter == *iter2)
            {
                a.erase(iter2);
                b.erase(iter);
                iter = b.begin();
                iter2 = a.begin();
                break;
            }else
            {
                iter2++;
            }
            }
            
        }
    if(a.size()==0)
        return true;
    else
        return false;
}


void outpur(vector<int> inv)
{
    for (vector<int>::iterator iter = inv.begin(); iter != inv.end();iter++)
    {
        cout << *iter << "-";
    }
    cout << endl;
}
int main()
{

    int inpu;//有范围
    //空格分隔的大数
    // string line;
    // vector<int> inpu;
    // getline(cin, line);
    // stringstream ss(line);
    // while(ss)
    // {
    //     int temp;
    //     ss >> temp;
    //     inpu.push_back(temp);
    // }
    //init(b)
    cin >> inpu;
    vector<int> inve = allo(inpu);
    vector<int> a2n;
    vector<int> n;
    for (int i = 1;;)//1开始 
    {
        //可能会涉及到大数
        ans.clear();
        a2n = powd(2, i);
        if(a2n.size()<inve.size())
            i++;
        else if (a2n.size()==inve.size())
        {
            if(check(a2n,inve))
            {
                outpur(inve);
                n.push_back(i);
            }
            
            i++;
        }else
        {
            break;
        }
    }
    //
    if(n.size() == 0)
    {
        cout << -1 << endl; //没有复合个数的n
    }
    system("pause");
    return 0;
}