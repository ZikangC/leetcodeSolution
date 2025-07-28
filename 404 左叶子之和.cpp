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
    int leftleaf(TreeNode* root,int flag){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right && flag == 1){
             return root->val;
        }
        return leftleaf(root->left,1) + leftleaf(root->right,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root){
            return 0;
        }
        int sum = leftleaf(root,0);
        return sum;
    }
};
