#include <iostream>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        string refer;
        for (vector<string>::iterator i = folder.begin(); i != folder.end() - 1&&i != folder.end();) //每一行string
        {
            refer = *i+'/';
            vector<string>::iterator j = i + 1;
            while(j!=folder.end() && (*j).substr(0,refer.size()) == refer )
            {
                folder.erase(j);
            }
            i = j;
            

        }
        return folder;
        }
};


int main()
{
    vector<string> folder = {
        "/a","/c/d", "/c/d/e","/c/f"

    }; 
    //"/a/b/c", "/a/b/d", "/a/b/ca","/a/b"};
    Solution so;
    vector<string> res = so.removeSubfolders(folder);
    return 0;
}