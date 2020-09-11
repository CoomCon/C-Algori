#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

void Maopa(vector<int> &a);

int main()
{
    vector<int> a = {4, 3, 21, 2, 3, 4, 5};

    Maopa(a);

    return 0;
 }

 //冒泡排序
 // 比较两个相邻的数据，如果前面的比后面的大，交换
 // 一次遍历可以保证最后一个数 肯定是最大的
 // 遍历第二遍 遍历到到第二个数 到第二个数肯定是第二大的我
 // 如果无交换的话就证明顺序是完好的
 void Maopa(vector<int> &a)
 {
     int n = a.size();
     bool Isreverse = false;
     for (int j = 0;j<n;j++)
     {
         Isreverse = false;
         for (int i = 0; i < n - j -1; i++) //小的往前站
         {
             if (a[i] > a[i + 1])
             {
                 swap(a[i], a[i + 1]);
                 Isreverse = true;
             }
         }
         if(!Isreverse)
         {
             break;
         }
     }

 }

 // 快速排序
 // 
 // 
 // 一趟快速排序的算法是： [1] 
// 1）设置两个变量i、j，排序开始的时候：i=0，j=N-1； [1] 
// 2）以第一个数组元素作为关键数据，赋值给key，即key=A[0]； [1] 
// 3）从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的值A[j]，将A[j]和A[i]的值交换； [1] 
// 4）从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的A[i]，将A[i]和A[j]的值交换； [1] 
// 5）重复第3、4步，直到i=j； (3,4步中，没找到符合条件的值，即3中A[j]不小于key,4中A[i]不大于key的时候改变j、i的值，使得j=j-1，i=i+1，直至找到为止。找到符合条件的值，进行交换的时候i， j指针位置不变。另外，i==j这一过程一定正好是i+或j-完成的时候，此时令循环结束）。 [1] 
 // 
// #include <iostreaM>

// using namespace std;

// class Solution {
// public:
//     string longestPrefix(string s) {
//         string res,temp;
//         if(s.size()==0)
//             return NULL;
//         //dp[i]定义为以i为结尾的最长快乐前缀
//         bool flag = false;
//         for(int i=1;i<=s.size()-1;i++) //不包含本身
//         {
//             flag = true;
//             temp = s.substr(0,i);
//             int indexi = i-1;
//             for(int j=s.size()-1;indexi>=0&&j>=0;j--)
//             {
//                 if(temp[indexi--] != s[j])
//                 {
//                     flag = false;
//                     break;
//                 }
                
//             }
//             if(flag)
//             {
//                 res = temp;
//             }

//         }

//         return res;
//     }
// };
// int main()
// {
//     Solution so;
//     string &&a = so.longestPrefix("aaaaa");
//     return 0;
// }