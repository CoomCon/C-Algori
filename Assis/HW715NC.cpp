#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        vector<int>::iterator pb = people.begin(),pe = people.end();
        while(pb<pe)
        {
            if( *pb + *pe < limit)
            {
                pe--;
            }
            pb++;
            res++;
        }
        return res;

    }

};

int process(int p[], int n[], int m)
{
    int res = -1;
    //贪心+回溯 //动规
    //退化成找零钱的问题


    return res;
}


vector<int> findcoin(vector<int> coins,int mount)
{
    vector<int> res;
    sort(res.begin(), res.end());
    return res;
}
int main()
{
    vector<int> people;
    people.push_back(3);
    people.push_back(2);
    people.push_back(2);
    people.push_back(1);
    int limit = 3;
    Solution so;
    cout << so.numRescueBoats(people, limit) << endl;

    int p[5] = {1, 3, 7, 11, 13};
    int n[5] = {0};
    string line;
    getline(cin, line);
    stringstream ss(line);
    for (int i = 0; i < 5;i++)
    {
        ss >> n[i];
    }
    getline(cin, line);
    int m;
    cin >> m;

    int res = process(p, n, m);


}