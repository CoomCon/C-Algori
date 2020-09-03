#include <iostream>
#include<set>
using namespace std;


string IsAllCharExist(char* pShortString,char* pLongString)
{
    string a = "true";
    string b = "false";
    char* twmps = pShortString;
    char* twmpl = pLongString;
    while(*twmps!='\0')
    {
        twmps = pShortString;
        twmpl = pLongString;
        while (  * twmps != * twmpl )
        {
            twmpl++;
        }
        if(* twmps == '\0' || * twmpl == '\0')
            return "false";
        
        pLongString = twmpl+1;
        
        while(  * twmpl != '\0' && * twmps == * twmpl  )
        {
            twmpl++;
            twmps++;
        }
        if(* twmps == '\0' )
            return "true";
        if(* twmpl == '\0' )
            return "false";
    }
    return "false";
    
}



int main()
{
    // char* pShortString = new(char);
    // char* pLongString = new(char);
    // cin>>pShortString;
    // cin>>pLongString;
    
    // cout<<IsAllCharExist(pShortString,pLongString)<<endl;
    
    // return 0;
    string a;
    string b;
    set<char> l;
    while (cin >> a >> b)
    {
        for (int i = 0; i < b.size();i++)
        {
            l.insert(b[i]);
        }

        for (int i = 0; i < a.size();i++)
        {
            if(l.count(a[i]) == 0 )
            {
                cout << "false" << endl;
                return 0;
            }
        }
        cout << "true" << endl;
    }
    return 0;
}