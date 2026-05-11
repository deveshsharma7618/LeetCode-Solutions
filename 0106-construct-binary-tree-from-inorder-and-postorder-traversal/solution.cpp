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
    int index;
    unordered_map<int, int> mp;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index = postorder.size() - 1;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return helper(postorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& postorder, int start, int end) {
        if (start > end)
            return nullptr;

        int rootVal = postorder[index--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];

        // IMPORTANT: build right subtree first
        root->right = helper(postorder, mid + 1, end);
        root->left = helper(postorder, start, mid - 1);

        return root;
    }
};
