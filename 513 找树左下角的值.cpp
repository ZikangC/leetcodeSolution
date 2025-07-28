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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int num = 1;
        int size = 1;
        int res;
        while(!q.empty()){
            num = size;
            size = 0;
            res = q.front()->val;
            while(num){
                if(q.front()->left){
                    q.push(q.front()->left);
                    size++;
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    size++;
                }
                q.pop();
                num--;
            }
        }
        return res;
    }
};
