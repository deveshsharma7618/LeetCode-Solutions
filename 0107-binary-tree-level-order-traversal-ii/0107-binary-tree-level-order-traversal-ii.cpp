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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return {};
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int V = q.size();
            vector<int> x;
            for (int i = 0; i < V; i++) {
                TreeNode* temp = q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

                q.pop();
                
                x.push_back(temp->val);
            }

            ans.push_back(x);

        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};