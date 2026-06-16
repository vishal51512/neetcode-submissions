class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;

        vector<vector<int>> directions = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        // Step 1: Push all treasure cells into queue
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // Step 2: BFS
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                if(grid[nr][nc] != INT_MAX) continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
