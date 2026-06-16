class Solution {
    int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int &area) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return;
        if(grid[r][c] == 0)
            return;

        grid[r][c] = 0;   // mark visited
        area++;

        for(auto &d : dirs) {
            dfs(grid, r + d[0], c + d[1], area);
        }
    }
};
