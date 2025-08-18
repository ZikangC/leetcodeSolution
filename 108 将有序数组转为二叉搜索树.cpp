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
    TreeNode* sortedpart(vector<int>& nums, int begin, int end){
        if(begin > end){
            return nullptr;
        }
        if(begin == end){
            TreeNode* root = new TreeNode(nums[begin]);
            return root;
        }
        int mid = (begin + end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedpart(nums,begin,mid-1);
        root->right = sortedpart(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedpart(nums,0,nums.size()-1);
    }
};
