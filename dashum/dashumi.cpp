#include   <iostream>
#include <vector>
using namespace std;

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


vector<int> powtemp(int n,int m) //n^m
{
    vector<int> res;
    int weishu = 0;
    int temp=n;
    for (int i = 1; i < m;i++)
    {
        temp *= n;

        if(temp % 10 > 0)
        {
            
        }
    }
    return res;
}

#define MAX 1000000
int nbit;
int ans[MAX];
 
void init(){
    nbit = 1;
    ans[0] = 1;
}
 


void mul(int num){
    int temp_add = 0;
    int temp_mul = 0;
    for(int i = 0; i < nbit; i++){
        temp_mul = num * ans[i];
        ans[i] = (temp_mul + temp_add) % 10;
        temp_add = (temp_mul + temp_add) / 10;
    }
    while(temp_add){
        ans[nbit++] = temp_add % 10;
        temp_add /= 10;
    }
}

void exp(int b, int e){
    for(int i = 0; i < e; i++) mul(b);
}

int main()
{
    int a = poww(4, 3);
    return 0;
}