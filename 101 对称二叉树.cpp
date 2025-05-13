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
    bool istrue(TreeNode* left,TreeNode* right){
        if(!left && !right){
            return true;
        }else if(!left || !right){
            return false;
        }
        if(left->val == right->val){
            return istrue(left->right,right->left)&&istrue(left->left,right->right); 
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return istrue(root->left,root->right);
    }
};
