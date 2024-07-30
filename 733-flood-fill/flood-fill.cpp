class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>>vis(m,vector<int>(n,0));
         queue<pair<int,int>>q;
         q.push({sr,sc});
         vis[sr][sc]=color;
         while(!q.empty())
         {
            int row = q.front().first;
            int col = q.front().second;
           if (row - 1 >= 0 && grid[row - 1][col] ==grid[row][col]  &&
                vis[row - 1][col] != color)
                {
                q.push({row - 1, col});
                vis[row - 1][col] = color;
                }
            if (row + 1 < m && grid[row + 1][col] ==grid[row][col]&&
                vis[row + 1][col] != color)
                {
                vis[row + 1][col] = color;
                q.push({row + 1, col});
                }
            if (col - 1 >= 0 && grid[row][col - 1] ==  grid[row][col]&&
                vis[row][col - 1] != color)
                {
                vis[row][col - 1] = color;

                q.push({row, col - 1});
                }
            if (col + 1 < n && grid[row][col + 1] == grid[row][col] &&
                vis[row][col + 1] != color)
                {    vis[row][col + 1] = color;
                q.push({row, col + 1});
                }
            q.pop(); 
         }
         
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]!=color)vis[i][j]=grid[i][j];
            }
         }
         return vis;

    }
};