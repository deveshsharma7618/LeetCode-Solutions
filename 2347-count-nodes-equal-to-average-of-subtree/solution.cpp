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
    pair<int, int> solve(TreeNode* root,int &ans){
        if(!root){
            return { 0, 0};
        }

        pair<int, int> leftSum = solve(root->left, ans);
        pair<int, int> rightSum = solve(root->right, ans);

        int avg = (root->val + leftSum.first + rightSum.first)/(1.0 + leftSum.second + rightSum.second);

        if( avg == root-> val){
            ans++;
        }

        return {
            root->val + leftSum.first + rightSum.first, 1.0 + leftSum.second + rightSum.second
        };




    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
