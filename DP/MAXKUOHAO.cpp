//32 最长有效括号
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int longestValidParentheses(string s) {
        //dp[i] 以i结尾的最长有效括号长度
        vector<int> dp(s.size()+1,0);
        dp[0] = 0; //
        int res = 0;
        for(int i = 1; i<s.size();i++)
         {
             if(s[i] == ')' && s[i-1] == '(') //  ()
             {
                 dp[i] = i>2 ? 2 + dp[i-2] : 2;
             }else if(s[i] == ')' && s[i-1] == ')'
             )
              {
                  if(i-1>=dp[i-1] && s[i-1-dp[i-1]] == '(')
                  {
                      dp[i] = i-2 > dp[i-1] ? 2+dp[i-1]+dp[i-2-dp[i-1]] : 2+dp[i-1] ;
                  }
              }
              res = max(dp[i],res);


         }
 
         return res;
    }   

};        


int main()
{
    string s;
    cin>>s;
    Solution so;
    cout<<so.longestValidParentheses(s)<<endl;
    return 0;

}