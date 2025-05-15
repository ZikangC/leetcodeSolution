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
    int deepcount(TreeNode* root) {
        if(!root){
            return 0;
        }
        return max(1+deepcount(root->left),1+deepcount(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        if(abs(deepcount(root->left)-deepcount(root->right))>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
