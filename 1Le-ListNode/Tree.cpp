#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


/*二叉树结构体，并且构建了有参构造函数*/
typedef struct BinaryTree{
    int val;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int data)
        :val(data), left(nullptr), right(nullptr){ 
    }
}BinaryTree,*pBinaryTre,TreeNode;


/*队列实现层序遍历从上至下*/
void printTree(BinaryTree* root)
{
    vector<int> res;
    queue<BinaryTree*> rel; //定义一个队列，数据类型是二叉树指针，不要仅是int！！不然无法遍历
    rel.push(root);
    
    while (!rel.empty())
    {
        BinaryTree* front = rel.front();
        res.push_back(front->val);
        cout << front->val << endl;
        rel.pop();                  //删除最前面的节点
        if (front->left != nullptr) //判断最前面的左节点是否为空，不是则放入队列
            rel.push(front->left);  
        if (front->right != nullptr)//判断最前面的右节点是否为空，不是则放入队列
            rel.push(front->right);
    }
}
/*栈实现层序遍历从下至上*/
static stack<TreeNode *> data;
void printTree2(TreeNode *root)
{
    
    if(root==NULL)
        return;
    data.push(root);
    printTree2(root->left);
    printTree2(root->right);
}
void printOut(stack<TreeNode *> data)
{
    //printTree2(root);
    while(!data.empty())
    {
        TreeNode *tmp = data.top();
        //cout << tmp->val << "->" << endl;
       
        data.pop();
    }

}

/**
 * 层序打印二叉树
 * 
*/








/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> Prequeue,que;
        vector<vector<int>> res;
        vector<int>  temp;
        if(root==NULL)
            return res;
        que.push(root);

        res.clear();

        while(!que.empty())  //队列不为空
        {

             temp.clear();
             int n =que.size();
             for(int i=0;i<n;i++)
             {
                 TreeNode* tmp = que.front();
                 //cout<<tmp->val<<endl;
                 temp.push_back(tmp->val);

                  if(tmp->left!=NULL)
                {
                    que.push(tmp->left);
                }
                if(tmp->right!=NULL)
                {
                  que.push(tmp->right);
                 }
                que.pop();
             }
             res.push_back(temp);
            //temp.push_back(tmp->val);
        }

        return res;
    }
};



int main()
{
    BinaryTree* s_arr[6];
    s_arr[0] = new BinaryTree(0);
    s_arr[1] = new BinaryTree(1);
    s_arr[2] = new BinaryTree(2);
    s_arr[3] = new BinaryTree(3);
    s_arr[4] = new BinaryTree(4);
    s_arr[5] = new BinaryTree(5);
    s_arr[0]->left = s_arr[1];  //   0
    s_arr[0]->right = s_arr[2]; //  1  2
    s_arr[1]->left = s_arr[3];  // 3     5
    s_arr[3]->left = s_arr[4];  //4
    s_arr[2]->right = s_arr[5]; //所以层序遍历的结果为：0 1 2 3 5 4

    vector<int> a={1, 2, 3, 4, 5, 6, 7};
    reverse(a.begin(), a.end());
    

    printTree2(s_arr[0]);
    printOut(data);

    return 0;
}