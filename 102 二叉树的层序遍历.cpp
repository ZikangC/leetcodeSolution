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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        vector<int> restmp;
        int T = 1;
        q.push(root);
        int tmp = 0;
        while(!q.empty()){
            restmp = {};
            while(T--){
                if(q.front()->left){
                    q.push(q.front()->left);
                    tmp++;
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    tmp++;
                }
                restmp.push_back(q.front()->val);
                q.pop();
            }
            res.push_back(restmp);
            T = tmp;
            tmp = 0;
        }
        return res;
    }
};
