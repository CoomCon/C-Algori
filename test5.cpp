#include <iostream>

using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        if (s.size() == 0)
            cout<<"false"<<endl;
        //if (atoi(s.c_str()) == 0)
            cout<<atoi(s.c_str())<<endl;
        
    }

    return 0;
}