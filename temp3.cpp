#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
 

 int main()
 {
     vector<int> price = {1, 3, 7, 11, 13};
     vector<int> num;
     string str;
     getline(cin, str);
     stringstream ss(str);
     int temp;

     for (int i = 0; i < 5;i++)
     {
         cin>>temp;
         num.push_back(temp);
     }
     int N;
     cin >> N;

     vector<int> f(N + 1, -99);

     for (int i = 1; i <= 5;i++)
     {
         for (int j = N; j >= 0;j--)
         {
             for (int k = 0; k <= num[i];k++)
             {
                 //f[i] = max(f[i],)
             }
         
         }
     }

         return 0;
 }
// #include <iostreaM>

// using namespace std;

// class Solution {
// public:
//     string longestPrefix(string s) {
//         string res,temp;
//         if(s.size()==0)
//             return NULL;
//         //dp[i]定义为以i为结尾的最长快乐前缀
//         bool flag = false;
//         for(int i=1;i<=s.size()-1;i++) //不包含本身
//         {
//             flag = true;
//             temp = s.substr(0,i);
//             int indexi = i-1;
//             for(int j=s.size()-1;indexi>=0&&j>=0;j--)
//             {
//                 if(temp[indexi--] != s[j])
//                 {
//                     flag = false;
//                     break;
//                 }
                
//             }
//             if(flag)
//             {
//                 res = temp;
//             }

//         }

//         return res;
//     }
// };
// int main()
// {
//     Solution so;
//     string &&a = so.longestPrefix("aaaaa");
//     return 0;
// }