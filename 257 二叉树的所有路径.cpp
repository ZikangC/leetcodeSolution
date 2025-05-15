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
    vector<string> res;
    void nodeget(TreeNode* root,string cur){
        string curleft = cur;
        string curright = cur;
        if(root->left){
            curleft+= "->";
            curleft+= to_string(root->left->val);
            nodeget(root->left,curleft); 
        }
        if(root->right){
            curright+= "->";
            curright+= to_string(root->right->val);
            nodeget(root->right,curright);
        }
        if(!root->left && !root->right){
            res.push_back(cur);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        nodeget(root,to_string(root->val));
        return res;
    }
};
