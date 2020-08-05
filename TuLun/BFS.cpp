#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
   TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> restemp={0};
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        res.push_back(restemp);
        if(root==NULL)
            return res;
        int level =0;
        DFS( root,level);
        return res;
    }
    
    void DFS(TreeNode* root,int level)
    {
        if(level > res.size())
        {
            res.push_back(restemp);
        }
        res[level].push_back(root->val);
        if( root -> left != NULL )
        {
            DFS(root->left,level+1);
        }
        if( root -> right != NULL )
        {
            DFS(root->right,level+1);
        }
        
    }
};

// void BFS(TreeNode *root)
// {
//      queue<int> data;
//     data.push(root);
//      while(!data.empty())
// {
//     TreeNode *temp = data.pop();
//     if(temp->left != NULL)
//     {
//         data.push(temp->left);
//     }
//     if(temp->right != NULL)
//     {
//         data.push(temp->right);
//     }
// }
// }

int main()
{
    //cout << data[2] << endl;
    return 0;
}