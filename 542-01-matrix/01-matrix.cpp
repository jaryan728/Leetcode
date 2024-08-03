class Solution {
public:
     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        // Initialize the queue with all 0 cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        // Process the queue
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            // Check the cell above
            if (row - 1 >= 0 && !vis[row-1][col]) {
                q.push({{row-1, col}, dis + 1});
                vis[row-1][col] = 1;
                ans[row-1][col] = dis + 1;
            }
            // Check the cell below
            if (row + 1 < m && !vis[row+1][col]) {
                q.push({{row+1, col}, dis + 1});
                vis[row+1][col] = 1;
                ans[row+1][col] = dis + 1;
            }
            // Check the cell to the left
            if (col - 1 >= 0 && !vis[row][col-1]) {
                q.push({{row, col-1}, dis + 1});
                vis[row][col-1] = 1;
                ans[row][col-1] = dis + 1;
            }
            // Check the cell to the right
            if (col + 1 < n && !vis[row][col+1]) {
                q.push({{row, col+1}, dis + 1});
                vis[row][col+1] = 1;
                ans[row][col+1] = dis + 1;
            }
        }

        return ans;
    }
};