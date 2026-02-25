class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> left, right;
        left.push(root->left);
        right.push(root->right);

        while (!left.empty() && !right.empty()) {
            TreeNode* lt = left.front(); left.pop();
            TreeNode* rt = right.front(); right.pop();

            if (!lt && !rt) continue;  // both null, symmetric at this level
            if (!lt || !rt) return false;  // one null, one not
            if (lt->val != rt->val) return false;  // values differ

            // push children in mirrored order
            left.push(lt->left);
            left.push(lt->right);

            right.push(rt->right);
            right.push(rt->left);
        }

        return left.empty() && right.empty();
    }
};
