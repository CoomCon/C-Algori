#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        int temp;
        
        int N = S.size();

        int len = 1;
       
         
         return process(S, len);;

    }

    vector<int> process(string str,int len)
    {
        bool isans = false;
        vector<int> ans;
        for (int i = 0; i < str.size() - 2*len;i+=len)
        {
            string str1 = str.substr(i, len);
            string str2 = str.substr(i+len,len);
            string str3 = str.substr(i+2*len,len);
            int ints1 = stoi(str1);
            int ints2 = stoi(str2);
            int ints3 = stoi(str3);
            if(!Che(ints1,ints2,ints3))
            {
                ans = process(str, ++len);
            }else
            {
                //这个地方有问题
                ans.push_back( ints1);
                ans.push_back( ints2);
                ans.push_back( ints3);
            }
        }
        return ans;
    }
    bool Che(int str1,int str2, int str3)
    {
        if(str1 + str2 == str3)
            return true;
        return false;
    }
};

int main()
{
    string s;
    Solution so;
    vector<int> ans;
    while(cin>>s)
    {
        ans = so.splitIntoFibonacci(s);
        for(vector<int>::iterator iter = ans.begin();iter!=ans.end();iter++)
            cout << *iter << " ";
        cout << endl;
    }
    return 0;

}