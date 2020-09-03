#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        multimap<string,string> data;
        vector<string> res;

        multimap<string, string>::iterator iterat;



        if(tickets.size()==0)
            return res;
        for(int i=0;i<tickets.size();i++)
        {
            if(data.count(tickets[i][0])>0)
            {
                for (iterat = data.find(tickets[i][0]); iterat != data.upper_bound(tickets[i][0]);iterat++)
                {
                    if()
                }
            }else
                data.insert(make_pair(tickets[i][0],tickets[i][1]));
        }

        res.push_back("JFK");
        //回溯+dfs
        int i = 1;
        res = dfs(res,data);

        return res;
    }

    vector<string> ans;
    multimap<string, string>::iterator iter,itert;
    int dfs(vector<string> &res, multimap<string, string> data)
    {
        //if(res.size() == data.size()+1)
        //    return;
        if(data.count(res.back()) == 0)
        {
            return -1;
        }else if(data.count(res.back()) > 1)
        {
            iter = data.find(res.back());
            
            for (itert = iter; itert != data.upper_bound(res.back());itert++)
            {  
                if (itert->second  < iter -> second)
                      iter = itert;
            }
            res.push_back(iter->second);
        
            dfs(res, data);
            res.pop_back();
        }
        
    }
};

// class Solution {
// public:
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         multimap<string,string> data;
//         vector<string> res;

//         multimap<string, string>::iterator iter,itertemp,iterLower,iterUpper;
//         //multimap<>

//         if(tickets.size()==0)
//             return res;
//         for(int i=0;i<tickets.size();i++)
//         {
//             // if(data.count(tickets[i][0]))
//             // {
//             //     iter = data.find(tickets[i][0]);
//             //     if(iter->second > tickets[i][1])
//             //         //data.insert(make_pair(tickets[i][0],tickets[i][1]));
//             //         //iter->second = tickets[i][1];
//             // }
//             // else
//             data.insert(make_pair(tickets[i][0],tickets[i][1]));
//         }
//         res.push_back("JFK");
        
//         for(int i=0;!data.empty() && i<tickets.size()  ;i++)
//         {
//             iter = data.find(res.back());
//             if(data.count(res.back()) >1)
//             {
//                 iterLower = iter;
//                 iterUpper = data.upper_bound(res.back());
//                 //iterLower++;
//                 for (;iterLower!=iterUpper; iterLower++)
//                 {
//                     if(iterLower ->second < iter->second )
//                         iter = iterLower;
//                 }
//             }
            
//             res.push_back(iter->second);

//             data.erase(iter);
//         }

//         return res;
//     }
// };


int main()
{
    //vector<vector<string>> ti = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    //vector<vector<string>> ti = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    //vector<vector<string>> ti = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"},
     //{"LHR", "SFO"}};
    vector<vector<string>> ti = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};

    Solution so;
   


    vector<string> res = so.findItinerary(ti);

    return 0;
}