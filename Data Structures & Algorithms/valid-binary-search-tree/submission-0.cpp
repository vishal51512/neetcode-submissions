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
static bool left_check(int val,int limit)
{
    return val < limit;

}
static bool right_check(int val,int limit){
    return val > limit;
}
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isvalid(root->left,root->val,left_check) || !isvalid(root->right,root->val,right_check)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
        
    }
    bool isvalid(TreeNode* root,int limit,bool (*check)(int,int))
    {
        if(!root) return true;
        if(!check(root->val,limit)) return false;
        return isvalid(root->left,limit,check) &&  isvalid(root->right,limit,check);
    }
};
