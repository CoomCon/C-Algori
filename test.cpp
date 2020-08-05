#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool Nom2Zi(string a)
{
    bool res = false;
    int tsg[5] = {0}; //小写 大写 数字 其他符号 总数
    for(int i=0;i<a.size();i++)
    {
        if(tsg[2] == 0 && isdigit(a[i]))
        {tsg[2]++;tsg[4]++;}
        else if(tsg[0] == 0 && islower(a[i]))
        {tsg[0]++;tsg[4]++;}
        else if(tsg[1] == 0 && isupper(a[i]))
        {tsg[1]++;tsg[4]++;}
        else if( tsg[3] == 0 && !isalnum(a[i]) ) //不是前面三种 
        {tsg[3]++;tsg[4]++;}
        
        if(tsg[4] >=3 )
        {res = true;
            break;}
            
    }
    
    return res;
}
bool isFCa(string a) //存在重复子串 true存在 false不存在
{
    bool res = false;
    int i=0;int j=0;
    for (int i = 0; i < a.size() - 5;i++){
        for (int j = i + 1; j < a.size() - 2 ; j++) //至少是3
        {
            if (a[i] == a[j] && a[i + 1] == a[j + 1] && a[i + 2] == a[j + 2])
            {
                res = true;
                break;
            }
        
    }
    }
    
    return res;
}

void process(string a)
{
    if(a.size()>8 && !isFCa(a) && Nom2Zi(a))
        cout<<"OK"<<endl;
    else
        cout<<"NG"<<endl;
}

int main()
{
    
    vector<string> str;
    string temp;
    while(cin>>temp)
    {
        process(temp);
    }
    return 0;
    
    
}