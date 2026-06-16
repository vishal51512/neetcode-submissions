/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;

    }
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int ls = dfs(root->left);
        if(ls == -1) return -1;
        int rs = dfs(root->right);
        if(rs == -1) return -1;
        if(abs(ls- rs)> 1) return -1;
        return 1+max(ls,rs);
    }
};
