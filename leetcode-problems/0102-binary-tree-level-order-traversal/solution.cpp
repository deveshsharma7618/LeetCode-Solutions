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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        q.push(root);
        q.push(NULL);
        vector<int> level_data;
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root){
                level_data.push_back(root->val);
            }else{
                ans.push_back(level_data);
                level_data.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            if(root && root->left){
                q.push(root->left);
            }

            if(root && root->right){
                q.push(root->right);
            }
        }

        return ans;
    }
};
