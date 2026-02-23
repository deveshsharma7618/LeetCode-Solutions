/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int& ans, int& curr_sum) {
        if (!root) {
            return;
        }
        // leaf node
        if (!root->left && !root->right) {
            cout << curr_sum*10 + root->val << endl;
            ans += curr_sum*10 + root->val;
        } else {
            curr_sum = curr_sum * 10 + root->val;
            solve(root->left, ans, curr_sum);
            solve(root->right, ans, curr_sum);

            curr_sum = curr_sum / 10;
        }
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int curr_sum = 0;
        solve(root, ans, curr_sum);
        return ans;
    }
};
