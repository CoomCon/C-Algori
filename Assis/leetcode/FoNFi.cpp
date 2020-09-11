//495 提莫攻击
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
    if(timeSeries.empty())
            return 0;
        for(int i = 0;i<timeSeries.size()-1;i++)
        {
            if(timeSeries[i]+duration>timeSeries[i+1])
                res+=timeSeries[i+1] - timeSeries[i];
            else
                res+=duration;
        }

        res += duration;//最后一次

        return res;
    }
};


int main()
{
    vector<int> timeSeries = {1, 4};
    int duration = 2;
    Solution so;
    int answer = so.findPoisonedDuration(timeSeries, duration);
    return 0;
}