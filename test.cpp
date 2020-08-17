// #include<iostream>
// #include <vector>
// #include <string>
// #include<sstream>
// /**
//  Definition for singly-linked list. */
// typedef struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// }ListNode,pListNode;

// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int m, int n) {
//         if(!head)
//             return head;

//         ListNode* gphead = head;
//         ListNode* gend = head;
//         int i=1;
        
//         while(i != m)
//         {
//             head= head->next;
//             i++;
//         }
//         gphead = head;
//         while(i!= n)
//         {
//             head = head ->next;
//             i++;
//         }
//         gend = head;
//         return reverse(gphead,gend);
//     }

//     ListNode* reverse(ListNode* head,ListNode* end)
//     {
//         ListNode* pre,*now,*next;
//         pre = NULL;
//         now = head;
//         next = head->next;
//         while(head!=end)
//         {
//             //指向更新
//             head->next = pre;
//             next->next = head;
            
//             pre = head;
//             head = next;
//             next = head ->next;
            
//         }
//         return end;
//     }
// };

// int main()
// {
//     int n = 8;
//     ListNode *head;
//     //= (ListNode *)malloc(sizeof(ListNode *));
//     ListNode *listnode = (ListNode*)malloc(sizeof(ListNode*));
//     //head->val(0);
//     head->val = 0;
//     ListNode *pre = head;
//     for (int i = 0; i < n;i++)
//     {
//         ListNode *listnode = (ListNode*)malloc(sizeof(ListNode*));

//         listnode->val = i;

//         pre->next = listnode;

//         pre = listnode;
//     }

//     Solution so;

//     ListNode *res = so.reverseBetween(head, 2, 4);

//     return 0;
// }
// #include<iostream>
// #include <vector>
// #include <string>
// #include<sstream>
// using namespace std;
// bool isSu(int a)
// {
//     if(a<4)
//         return true;
//     for(int ii=3;ii<a/2;ii++)
//     {
//         if(a%ii==0)
//             return false;
//     }
//     return true;
// }
// int process(vector<int> data,vector<int>::iterator iter1,vector<int>::iterator iter2,bool isF)
// {
//     if(data.size()==0)
//         return 0;

//     int res = 0;
//     if(!isF)
//     {
//         data.erase(iter1);
    
//         data.erase(iter2);
//         }
//     for(vector<int>::iterator iteri=data.begin();iteri!=data.end()-1;iteri++)
//     {
//         for(vector<int>::iterator iterj=iteri+1;iterj!=data.end();iterj++)
//         {
//             if(isSu(*iteri+*iterj))
//                 res=max(1+process(data,iteri,iterj,false),res);
//         }
//     }
//     return res;
// }
// int main()
// {
//     int n;
//     vector<int> data;
//     cin >> n;
//     string str;
//     getline(cin, str);
//     getline(cin, str);
//     stringstream ss(str);
//     int temp;
//     for (int i = 0; i < n; i++)
//     {
//         ss >> temp;
//         data.push_back(temp);
//         }
//     vector<int>::iterator iteri=data.begin();
//     int res = process(data,iteri,iteri,true);
//     cout<<res<<endl;

//     return 0;
// }



// // #include <iostream>
// // #include <vector>
// // #include <algorithm>
// // using namespace std;

// // class Solution {
// // public:
// //    int countBinarySubstrings(string s) {

// //         vector<int> counts;

// //         for(int i=0;i<s.size();)
// //         {
// //             char refer = s[i];
// //             int j=i+1;
// //             for(;j<s.size();j++)
// //             {
// //                 if(s[j] != refer)
// //                     {counts.push_back(j-i); break;}
// //             }
// //             i=j;
// //         }
// //         int res = 0;
// //         for(int i=1;i<counts.size();i++)
// //         {
// //             res+=min(counts[i-1],counts[i]);
// //         }

// //         return res;
// //     }
    
// // };

// // int main()
// // {
// //     string s = "00110011";
// //     Solution so;
// //     cout<<so.countBinarySubstrings(s)<<endl;

// //     return 0;
// // }


// // // int main()
// // // {
// // //     long a;
// // //     cin>>a;
// // //     vector<int> res;
// // //     for(int i=2 ; i< a/2;)
// // //     {
// // //         if(a%i==0)
// // //             res.push_back(i);
// // //         else
// // //             i++;
// // //     }
// // //     sort(res.begin(),res.end());
// // //     for(vector<int>::iterator iter = res.begin();iter!=res.end();iter++)
// // //         cout<<*iter<<" ";
// // //     cout<<endl;
// // // }
// // // #include<stdlib.h>
// // // #include<stdio.h>

// // // int main()
// // // {
// // //     long long a;
// // //     do{
// // //     scanf("0x%x",&a);
// // //     printf("%d\n",a);
// // //     }while(getchar()!='\n');
    
// // //     return 0;
// // // }

// // // #include <iostream>
// // // #include <string>
// // // #include <sstream>
// // // #include <vector>
// // // #include <algorithm>
// // // using namespace std;

// // // int main()
// // // {

// // //     int n;
// // //     string a(0, '0');
// // //     vector<int> data;
// // //     while(cin>>n)
// // //     {
// // //         for(int i=0;i<n;i++)
// // //         {
// // //             int temp;
// // //             cin>>temp;
// // //             data.push_back(temp);
// // //         }
        
        
        
// // //     }
// // //     //process
// // //     sort(data.begin(),data.end());
    
// // //     for(int i=0;i<data.size();i++)
// // //         cout<<data[i]<<endl;
// // //     return 0;
// // // }