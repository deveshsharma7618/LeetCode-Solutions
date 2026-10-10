
class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& adj,
             vector<bool>& visited, int& timer, vector<int>& disc,
             vector<int>& low, vector<vector<int>>& bridges) {

        visited[node] = true;
        disc[node] = low[node] = timer++;

        for (int neig : adj[node]) {

            if (neig == parent) {
                continue;
            }

            if (!visited[neig]) {
                dfs(neig, node, adj, visited, timer, disc, low, bridges);

                low[node] = min(low[node], low[neig]);

                // Bridge condition
                if (low[neig] > disc[node]) {
                    bridges.push_back({node, neig});
                }
            } else {
                // Back edge
                low[node] = min(low[node], disc[neig]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<int> disc(n, -1), low(n, -1);
        vector<vector<int>> bridges;
        int timer = 0;

        dfs(0, -1, adj, visited, timer, disc, low, bridges);

        return bridges;
    }
};
