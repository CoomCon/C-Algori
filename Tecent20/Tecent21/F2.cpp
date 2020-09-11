#include<iostream>
#include<string>
#include<vector>
#include <sstream>
#include<algorithm>
#include <queue>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> data;
    string line;
    queue<int> tocheck;
    tocheck.push(0);
    int numofchongfu = 0;
    vector<int> xi(m,0);
    vector<bool> visited(m, 0);
    int ans = 0;

    bool flag = false;


    for (int i = 0;i<m;i++)
    {
        flag = false;
        cin>>xi[i];
        
        int tmp;
        vector<int> datatemp;
        
        for(int j=0;j<xi[i];j++)
        {
            if(tmp==0)
                flag = true;
            datatemp.push_back(tmp);
        }
        if(flag)
        {  
            ans += xi[i];
            for (int ii = 0; ii < datatemp.size() ;ii++)
            {
                if(datatemp[ii]!=0)
                    tocheck.push(datatemp[ii]);
            }
        }else{
            sort(datatemp.begin(), datatemp.end());
            data.push_back(datatemp);
        }
    }
    tocheck.pop(); //0 out
    while(!tocheck.empty())
    {
        int nextone = tocheck.front();
        for (int i = 0; i < data.size()  ;i++) //为访问过
        {
             for (int j = 0; j < data[i].size() && visited[i] == false;j++)
            {

                if(data[i][j]==nextone)
                {
                    ans += xi[i]; //有重叠的
                    numofchongfu++;
                    //入队
                    for (int jj = 0;jj < data[i].size() ;jj++)
                    {
                        if(data[i][jj] != nextone)
                        tocheck.push(data[i][jj]);
                    }
                    visited[i] = true;

                }else if(data[i][j]>nextone)
                {
                    break;
                }
            }
        }
        tocheck.pop();
    }
    cout << ans-numofchongfu << endl;
    return 0;
    
}

// #include<iostream>
// #include<string>
// #include<vector>
// #include <sstream>
// #include<algorithm>
// #include <queue>

// using namespace std;

// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<vector<int>> data;
//     string line;
//     queue<int> tocheck;
//     tocheck.push(0);

//     vector<int> xi(m,0);
//     vector<bool> visited(m, 0);
//     int ans = 0;

//     bool flag = false;


//     for (int i = 0;i<m;i++)
//     {
//         flag = false;
//         getline(cin, line);
//         stringstream ss(line);
        
//         ss >> xi[i];
//         int tmp;
//         vector<int> datatemp;
//         while(ss>>tmp)
//         {
//             if(tmp==0)
//                 flag = true;
//             datatemp.push_back(tmp);
//         }
//         if(flag)
//         {  
//             ans += xi[i];
//             for (int ii = 0; ii < datatemp.size() ;ii++)
//             {
//                 if(datatemp[ii]!=0)
//                     tocheck.push(datatemp[ii]);
//             }
//         }else{
//             sort(datatemp.begin(), datatemp.end());
//             data.push_back(datatemp);
//         }
//     }
//     tocheck.pop(); //0 out
//     while(!tocheck.empty())
//     {
//         int nextone = tocheck.front();
//         for (int i = 0; i < data.size()  ;i++) //为访问过
//         {
//             for (int j = 0; j < data[i].size() && visited[i] == false;j++)
//             {

//                 if(data[i][j]==nextone)
//                 {
//                     ans += xi[i];
//                     //入队
//                     for (int jj = 0;jj < data[i].size() ;jj++)
//                     {
//                         if(data[i][jj] != nextone)
//                             tocheck.push(data[i][jj]);
//                     }
//                     visited[i] = true;

//                 }else if(data[i][j]>nextone)
//                 {
//                     break;
//                 }
//             }
//         }
//         tocheck.pop();
//     }
//     cout << ans << endl;
//     return 0;
    
// }