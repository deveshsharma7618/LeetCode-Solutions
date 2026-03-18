class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int ans = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans++;

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = true;

                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();

                        // 4 directions
                        int dr[] = {-1, 1, 0, 0};
                        int dc[] = {0, 0, -1, 1};

                        for(int k = 0; k < 4; k++){
                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if(nr >= 0 && nr < rows &&
                               nc >= 0 && nc < cols &&
                               !visited[nr][nc] &&
                               grid[nr][nc] == '1'){
                                
                                q.push({nr, nc});
                                visited[nr][nc] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
