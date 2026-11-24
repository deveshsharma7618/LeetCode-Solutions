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
    // Function to perform iterative inorder traversal
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        TreeNode* curr = root;

        // The loop continues if there are still unvisited nodes
        // or if there are nodes left in the stack to backtrack to.
        while (curr != nullptr || !s.empty()) {

            // 1. Reach the left-most node of the current node
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            // 2. Current must be nullptr at this point, so pop from stack
            curr = s.top();
            s.pop();

            // Add the node's value to our result vector
            result.push_back(curr->val);

            // 3. We have visited the node and its left subtree.
            // Now, it's the right subtree's turn.
            curr = curr->right;
        }

        return result;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder = inorderTraversal(root);

        int start = 0;
        int end = inorder.size() - 1;
        while (start < end) {
            int sum = inorder[start] + inorder[end];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                start++;
            } else {
                end--;
            }
        }

        return false;
    }
};