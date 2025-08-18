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
    int nodecnt(TreeNode* root, unordered_map<TreeNode*,int>& mp){
        if(!root){
            return 0;
        }
        int left = nodecnt(root->left,mp);
        int right = nodecnt(root->right,mp);
        mp[root] = left + right + 1;
        return mp[root];
    }
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*,int> mp;
        int cnt = nodecnt(root,mp);
        if(mp[root->left] == k - 1){
            return root->val;
        }else if(mp[root->left] < k - 1){
            return kthSmallest(root->right, k - mp[root->left]-1);
        }else{
            return kthSmallest(root->left, k);
        }
        return 0;
    }
};
