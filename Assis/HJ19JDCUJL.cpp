#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string ProcessInt(int n);//
void ProcessW(string ZS, string XS,int i,bool isb);//处理整数
void ProcessXS(string XS, int i);//处理小数

void ProcessXS(string XS, int i)
{
    switch (i) //只存在 角 分 和 整的情况
    {
    case 2:

             if(XS[0] == '0' && XS[1] == '0')
             {
                 cout<<"整";
                 break;
             }
             else{
                 cout<<ProcessInt(XS[0]-'0');
                 cout<<"角";
                 ProcessXS(XS.substr(1,1), 1);
             }
        break; 
    case 1:
        if(XS[0] == '0')
        {cout<<"整";break;}
        else   
                {
                    cout<<ProcessInt(XS[0]-'0');
                    cout<<"分";
                }

        break;
    defaut:
    
 
                 
        break;
    }
}


void ProcessW(string ZS, string XS,int i,bool isb)
{
    if(i==0 && isb)
    {
        cout<<"元";
        ProcessXS(XS ,XS.size()>2?2:XS.size());
    }else 
    if (ZS.size()>8 )//亿
    {
       ProcessW(ZS.substr(0,ZS.size()-8),XS , ZS.size()-8,false);
       cout<<"亿";
       ProcessW(ZS.substr(ZS.size()-8,8),XS ,8,false);
    }else
     if(ZS. size()>4 )
    {
        ProcessW(ZS.substr(0,ZS.size()-4),XS , ZS.size()-4,false);
        cout<<"万";
        ProcessW(ZS.substr(ZS.size()-4,4),XS ,4,true);//处理完 4位以上的 就只有四位一下的
    }else
    if(ZS.size() == 4)
    {
        cout<<ProcessInt((ZS[0]-'0'));//char转int
        cout<<"仟";
        ProcessW(ZS.substr(ZS.size()-3,3),XS , 3,isb);
    }else if(ZS.size() == 3)
    {

        cout<<ProcessInt((ZS[0]-'0'));//char转int

        cout<<"佰";
        ProcessW(ZS.substr(1,2),XS , 2,isb);
    }else if(ZS.size() == 2)
    {
        if(ZS[0] != '1')
            cout<<ProcessInt((ZS[0]-'0'));//char转int
        cout<<"拾";
        ProcessW(ZS.substr(1,2),XS , 1,isb);
    }
    else if(ZS.size()  == 1)
    {
        cout<<ProcessInt(stoi(ZS));
        if(isb)
            ProcessW("0",XS , 0,isb);
    }
    
    
}
    
     
       
void tran(double s)
{
    /* stringstream ss;
    ss << s;
    string str ;
    ss >> str; */
    string str;
    str = to_string(s);
    string ZS, XS;
    for (int i = 0; i<str.size();i++)
    {
        if (str[i]=='.')
        {
            ZS = str.substr(0, i);
            XS = str.substr(i+1, str.size()-i);
            break;
        }
    }
    if(ZS.size() == 1 && ZS[0] == '0')//处理开头就是0的情况
    {
        ProcessXS(XS,XS.size ()>2?2:XS.size ());
    }else{
    ProcessW(ZS,XS,ZS.size (),ZS.size ()>4?false:true) ;}
    //cout<<ZS<<endl ;
 

     }

string ProcessInt(int n)
{
    switch (n)
    {
    case 0:
        return "零";
    case 1:
        return "壹";
    case 2:
        return "贰";    
    case 3:
        return "叁";
    case 4:
        return "肆";
    case 5:
        return "伍";
    case 6:
        return "陆";
    case 7:
        return "柒";
    case 8:
        return "捌";
    case 9:
        return "玖";
    default:
        break;
    }
    return "";
}

int main()
{
    double sss;
    cin>>sss;
    cout<<"人民币";
    tran(sss);

    return 0;
}