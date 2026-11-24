/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getAncestor(TreeNode* root, TreeNode* p, vector<TreeNode*>& pAnc) {
        if (!root) {
            return false;
        }

        // Add the current node to the path
        pAnc.push_back(root);

        // Check if the current node is the target
        if (root == p) {
            return true;
        }

        // Recurse on left and right subtrees
        if (getAncestor(root->left, p, pAnc) ||
            getAncestor(root->right, p, pAnc)) {
            return true;
        }

        // Target not found in either subtree; backtrack
        pAnc.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> qAnc;
        vector<TreeNode*> pAnc;
        getAncestor(root, q, qAnc);
        getAncestor(root, p, pAnc);

        for (int i = 0; i < min(qAnc.size(), pAnc.size()); i++) {
            if (pAnc[i] != qAnc[i]) {
                return pAnc[i - 1];
            }
        }

        return qAnc[min(qAnc.size(), pAnc.size()) - 1];
    }
};