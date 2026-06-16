class Solution {
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0 ;j<cols;j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
void dfs(vector<vector<char>>& grid,int r,int c)
{
    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') return;
    grid[r][c] = '0';
    for(int i = 0 ; i < 4;i++)
    {
        dfs(grid,r+d[i][0],c+d[i][1]);
    }
}
};
