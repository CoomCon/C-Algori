#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string ProcessInt(int n);//
void ProcessW(string ZS, string XS,int i,bool isb);//��������
void ProcessXS(string XS, int i);//����С��

void ProcessXS(string XS, int i)
{
    switch (i) //ֻ���� �� �� �� �������
    {
    case 2:

             if(XS[0] == '0' && XS[1] == '0')
             {
                 cout<<"��";
                 break;
             }
             else{
                 cout<<ProcessInt(XS[0]-'0');
                 cout<<"��";
                 ProcessXS(XS.substr(1,1), 1);
             }
        break; 
    case 1:
        if(XS[0] == '0')
        {cout<<"��";break;}
        else   
                {
                    cout<<ProcessInt(XS[0]-'0');
                    cout<<"��";
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
        cout<<"Ԫ";
        ProcessXS(XS ,XS.size()>2?2:XS.size());
    }else 
    if (ZS.size()>8 )//��
    {
       ProcessW(ZS.substr(0,ZS.size()-8),XS , ZS.size()-8,false);
       cout<<"��";
       ProcessW(ZS.substr(ZS.size()-8,8),XS ,8,false);
    }else
     if(ZS. size()>4 )
    {
        ProcessW(ZS.substr(0,ZS.size()-4),XS , ZS.size()-4,false);
        cout<<"��";
        ProcessW(ZS.substr(ZS.size()-4,4),XS ,4,true);//������ 4λ���ϵ� ��ֻ����λһ�µ�
    }else
    if(ZS.size() == 4)
    {
        cout<<ProcessInt((ZS[0]-'0'));//charתint
        cout<<"Ǫ";
        ProcessW(ZS.substr(ZS.size()-3,3),XS , 3,isb);
    }else if(ZS.size() == 3)
    {

        cout<<ProcessInt((ZS[0]-'0'));//charתint

        cout<<"��";
        ProcessW(ZS.substr(1,2),XS , 2,isb);
    }else if(ZS.size() == 2)
    {
        if(ZS[0] != '1')
            cout<<ProcessInt((ZS[0]-'0'));//charתint
        cout<<"ʰ";
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
    if(ZS.size() == 1 && ZS[0] == '0')//����ͷ����0�����
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
        return "��";
    case 1:
        return "Ҽ";
    case 2:
        return "��";    
    case 3:
        return "��";
    case 4:
        return "��";
    case 5:
        return "��";
    case 6:
        return "½";
    case 7:
        return "��";
    case 8:
        return "��";
    case 9:
        return "��";
    default:
        break;
    }
    return "";
}

int main()
{
    double sss;
    cin>>sss;
    cout<<"�����";
    tran(sss);

    return 0;
}