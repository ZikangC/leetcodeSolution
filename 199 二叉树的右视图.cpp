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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> q;
        int tmp = 1;
        int cnt = 1;
        vector<int> res;
        q.push(root);
        while(!q.empty()){
            cnt = tmp;
            tmp = 0;
            while(cnt--){
                if(q.front()->left){
                    q.push(q.front()->left);
                    tmp++;
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    tmp++;
                }
                if(cnt == 0){
                    res.push_back(q.front()->val);
                }
                q.pop();
            }
        }
        return res;
    }
};
