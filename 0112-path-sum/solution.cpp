class Solution {
    int ans = 0;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        ans += root->val;

        if (!root->left && !root->right && ans == targetSum) {
            return true;
        }

        bool k = hasPathSum(root->left, targetSum) ||
                 hasPathSum(root->right, targetSum);

        ans -= root->val;
        return k;
    }
};
