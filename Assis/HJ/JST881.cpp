//881 救生艇
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        vector<int>::iterator pb = people.begin(),pe = people.end()-1;
        while(pb<=pe)
        {
            if( *pb + *pe <= limit)
            {
                pb++;
            }
            pe--;
            res++;
        }
        return res;

    }


};

int main()
{
    vector<int> people = {3,5,3,4};
    int limit = 5;
    Solution sol;
    int res = sol.numRescueBoats(people, limit);
    cout << res << endl;
    return 0;
}