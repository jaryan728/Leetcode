class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int m = grid.size();
        int n = grid[0].size();
         vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j},0});
                    vis[i][j]=2;

                }
            }
        }
    
        int c = 0;
        while (!q.empty())

        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t=q.front().second;
                c=max(c,t);

            vis[row][col] = 2;
            if (row - 1 >= 0 && grid[row - 1][col] == 1 &&
                vis[row - 1][col] != 2)
                {
                q.push({{row - 1, col},t+1});
                vis[row - 1][col] = 2;
                }
            if (row + 1 < m && grid[row + 1][col] == 1 &&
                vis[row + 1][col] != 2)
                {
                vis[row + 1][col] = 2;
                q.push({{row + 1, col},t+1});
                }
            if (col - 1 >= 0 && grid[row][col - 1] == 1 &&
                vis[row][col - 1] != 2)
                {
                vis[row][col - 1] = 2;

                q.push({{row, col - 1},t+1});
                }
            if (col + 1 < n && grid[row][col + 1] == 1 &&
                vis[row][col + 1] != 2)
                {    vis[row][col + 1] = 2;
                q.push({{row, col + 1},t+1});
                }
            q.pop();
        }

        for(int i=0;i<vis.size();i++)
        {
            for(int j=0;j<vis[i].size();j++)
            {
                if(grid[i][j]!=0&&vis[i][j]==0)return -1;
            }
        }
        return c;
    }
};