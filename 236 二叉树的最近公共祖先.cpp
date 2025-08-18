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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,TreeNode*> mp;
        queue<TreeNode*> qu;
        mp[root] = NULL;
        qu.push(root);
        while(!qu.empty()){
            if(qu.front()->left){
                mp[qu.front()->left] = qu.front();
                qu.push(qu.front()->left);
            }
            if(qu.front()->right){
                mp[qu.front()->right] = qu.front();
                qu.push(qu.front()->right);
            }
            qu.pop();
        }
        
        while(mp[p] != NULL){
            TreeNode* tmp = mp[p];
            mp[p] = NULL;
            p = tmp;
        }
        while(mp[q] != NULL){
            TreeNode* tmp = mp[q];
            mp[q] = NULL;
            q = tmp;
        }
        return q;
    }
};
