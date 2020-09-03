#include <iostream>
#include <vector>
#include <deque>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0 || k <= 0 || k > nums.size()) return {};
        vector<int> ret;
        deque<int> dq;
        int i = 0;
        for(; i < k; ++i){
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        ret.push_back(nums[dq.front()]);
        while(i < nums.size()){
            //判断队头的值是否已经不在滑动窗口中了
            if(i - dq.front() >= k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            i++;
            ret.push_back(nums[dq.front()]);
        }
        
        return ret;
    }
};



int main()
{
    vector<int> dat = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution so;
    vector<int> res = so.maxSlidingWindow(dat, k);

    return 0;
}
// #include <iostream>
// #include <map>
// #include <string>
// #include <cctype>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <set>
// using namespace std;


//  bool cmp(const pair<char,int> &p1,const pair<char,int> &p2)//要用常数，不然编译错误 
//  {
//  	return p1.second>p2.second; 
//  }


// int main()
// {
//     priority_queue<char> pqeue;
//     map<char,int> data;
//     string str;
    
//     getline(cin,str);
//     map<char, int>::iterator iter;
//     vector<int> index;


//      set<int> ggg;
//         for(int i=0;i<index.size();i++)
//         {
//             //cout << ggg[i] << endl;
//         }

//     for(int i=0;i<str.size();i++)
//     {
//         if(isalnum(str[i])||str[i] == ' ')
//         {
//             if(data.count(str[i])) //找到了
//             {
//                 iter = data.find(str[i]);
//                 iter->second++;
//             }
//             else
//                 data.insert(make_pair(str[i], 1));
//             //
            
//         }
//     }

//     //for (map<char, int>::iterator iter = data.begin();iter!=)
//      //   int res = data2.count(str[0]);
//     vector< pair<char, int> > dd;
//     for (map<char, int>::iterator iter = data.begin(); iter != data.end();iter++)
//     {
//         dd.push_back( make_pair ( iter->first, iter->second) );
//     }

//     sort(dd.begin(), dd.end(), cmp);

//     for (vector<pair<char, int>>::iterator iter2 = dd.begin(); iter2 != dd.end();iter2++)
//     {
//         cout << iter2->first << "";
//     }
//     cout << endl;
// }