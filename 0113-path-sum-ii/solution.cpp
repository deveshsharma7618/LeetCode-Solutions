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
    void solve(TreeNode* root, int currSum, vector<vector<int>>& ans,
               vector<int>& temp, int target) {
        if (!root->left && !root->right) {
            currSum += root->val;
            temp.push_back(root->val);
            if (target == currSum) {
                ans.push_back(temp);
            }
            currSum -= root->val;
            temp.pop_back();
            return;
        }

        currSum += root->val;
        temp.push_back(root->val);
        if (root->left) {
            solve(root->left, currSum, ans, temp, target);
        }

        if (root->right) {
            solve(root->right, currSum, ans, temp, target);
        }

        currSum -= root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        vector<int> temp;
        int currSum = 0;
        solve(root, currSum, ans, temp, targetSum);
        return ans;
    }
};
