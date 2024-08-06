class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>&vis)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row-1>=0&&!vis[row-1][col]&&board[row-1][col]=='O')
            {
                vis[row-1][col]=1;
                q.push({row-1,col});

            }
             if(row+1<board.size()&&!vis[row+1][col]&&board[row+1][col]=='O')
            {
                vis[row+1][col]=1;
                 q.push({row+1,col});
                
            }
             if(col+1<board[0].size()&&!vis[row][col+1]&&board[row][col+1]=='O')
            {
                vis[row][col+1]=1;
                 q.push({row,col+1});
                
            }
              if(col-1>=0&&!vis[row][col-1]&&board[row][col-1]=='O')
            {
                vis[row][col-1]=1;
                 q.push({row,col-1});
                
            }

        }
    }
    void solve(vector<vector<char>>& board) {
    int m=board.size();
    int n=board[0].size();
    vector<vector<int>>vis(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j]&&(i==0||j==0||i==m-1||j==n-1)&&board[i][j]=='O')
            {
                bfs(i,j,board,vis);
            }
        }
    }   
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j]&&board[i][j]=='O')
            {
                board[i][j]='X';
            }
        }
    }   
    
    }
};