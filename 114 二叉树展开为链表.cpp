class Solution {
public:
    pair<TreeNode*, TreeNode*> flattenpart(TreeNode* root) {
        if (!root) return {nullptr, nullptr};
        if (!root->left && !root->right) {
            return {root, root};
        }
        TreeNode* tmp = root->right;
        auto left = flattenpart(root->left);
        auto right = flattenpart(root->right);
        
        
        if (root->left) {
            root->right = left.first;
            root->left = nullptr;  // 必须置空左指针
            if (tmp) {
                left.second->right = right.first;
                return {root, right.second};
            }
            return {root, left.second};
        }
        root->right = right.first;
        return {root, right.second};
    }

    void flatten(TreeNode* root) {
        flattenpart(root);
    }
};
