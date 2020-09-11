//1000  合并石头未解决
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int res = 0;
    int mergeStones(vector<int>& stones, int K) {
    
        if(stones.size() ==1 )
            return res+stones[0];

        for(vector<int>::iterator iter = stones.begin();iter!= stones.begin() +K-1 ;iter++)
        {
            stones[K-1]+=*iter;
            stones.erase(iter);
            if(stones.empty())
                return -1;
        }
        res += stones[K - 1];
        return mergeStones(stones, K);
    }
    
};

int main()
{
    vector<int> stones = {3, 2, 1, 4};

    int K = 2;

    Solution so;
    cout << so.mergeStones(stones, K);
    return 0;
}
