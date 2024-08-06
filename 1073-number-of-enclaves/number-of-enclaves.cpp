class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& board,
             vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if (row - 1 >= 0 && !vis[row - 1][col] &&
                board[row - 1][col] == 1) {
                vis[row - 1][col] = 1;
                q.push({row - 1, col});
            }
            if (row + 1 < board.size() && !vis[row + 1][col] &&
                board[row + 1][col] == 1) {
                vis[row + 1][col] = 1;
                q.push({row + 1, col});
            }
            if (col + 1 < board[0].size() && !vis[row][col + 1] &&
                board[row][col + 1] == 1) {
                vis[row][col + 1] = 1;
                q.push({row, col + 1});
            }
            if (col - 1 >= 0 && !vis[row][col - 1] &&
                board[row][col - 1] == 1) {
                vis[row][col - 1] = 1;
                q.push({row, col - 1});
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int cnt = 0;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && board[0][i] == 1)
                bfs(0, i, board,vis);
                 if (!vis[m - 1 ][i] && board[m - 1][i] == 1)
                    bfs(m  - 1, i, board, vis);
        }
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && board[i][0] == 1)
                bfs(i, 0, board, vis) ;
                    if (!vis[i][n - 1 ] && board[i][n - 1 ] == 1)
                    bfs(i, n - 1 , board, vis);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};