class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>> q;
       int fresh = 0;
       int time = 0;
       for(int r = 0 ; r < grid.size();r++)
       {
        for(int c = 0; c<grid[0].size();c++)
        {
            if(grid[r][c] == 1 ) fresh++;
            if(grid[r][c] == 2) q.push({r,c});
        }
       }
       vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
       while(fresh > 0 && !q.empty())
       {
        int len = q.size();
        for(int i = 0; i<len;i++)
        {
            auto cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;
            for(const auto& dir:directions)\
            {
                int row = r+dir.first;
                int cols = c + dir.second;
                if(row >= 0 && row < grid.size() && cols >= 0 && cols < grid[0].size() && grid[row][cols] == 1)
                {
                    grid[row][cols] = 2;
                    q.push({row,cols});
                    fresh--;
                }
            }
        }
        time++;
       }
return fresh == 0 ? time : -1;
        
    }
};
