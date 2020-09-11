#include <iostream>
#include <map>
#include <vector>

// 1.合并瓜子。一个数组对应位置元素表示该堆瓜子数目
//。合并规则是只能合并相邻的两堆并且需要保证合并之后数组整体和最小，求最终合成一堆得到的数。
// 2.补完循环字符串。一个初始字符串s，后边接一个t，
// 求最短的t的长度，能保证s+t是一个包含循环子串的字符串。
// 3.求期望值。有两套题，每套题有2个题目，
// 每天只刷一个题，求第三天第二套题只剩一个题目的期望。

using namespace std;


int main()
{
    int nums[]  = {3, 3,3,3, 3};
    int t = 6;
    map<int, vector<int>> data ;

    vector<int> res;

    for (int i = 0; i < sizeof(nums);i++)
    {
        if(data.count(nums[i]))
        {
            for(auto curindex : data.find(nums[i]) ->second ) //输出所有的
            {
                res.push_back(curindex);
                res.push_back(i);
            }
        }
        if(data.count(t-nums[i]))
        {
            data.find(t - nums[i])->second.push_back(i);
        }
        else
        {
            vector<int> list;
            list.push_back(i);
            data.insert(make_pair(t - nums[i], list));
        }
    }

    for(int i=0;i<res.size();i++)
        cout << res[i] << endl;

    return 0;
}