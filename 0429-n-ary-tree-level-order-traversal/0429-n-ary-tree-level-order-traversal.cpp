/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) {
            return {};
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int V = q.size();
            vector<int> x;

            for (int i = 0; i < V; i++) {
                Node* temp = q.front();
                q.pop();

                for (int i = 0; i < temp->children.size(); i++) {
                    q.push(temp->children[i]);
                }

                x.push_back(temp->val);
            }
            ans.push_back(x);
        }
        return ans;
    }
};