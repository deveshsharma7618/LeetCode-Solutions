
class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int s,
             vector<int>& visited, vector<int>& ans) {

        if (visited[s] == 1) return false;

        if (visited[s] == 2) return true;

        visited[s] = 1;

        for (int v : adj[s]) {
            if (!dfs(adj, v, visited, ans)) {
                return false;
            }
        }

        visited[s] = 2;
        ans.push_back(s);

        return true;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(adj, i, visited, ans)) {
                return {};
            }
        }

        return ans;
    }
};
