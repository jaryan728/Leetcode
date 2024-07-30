class Solution {
public:
    bool issafe(int i,int j,char c,vector<vector<char>>& board)
    {
        for(int k=0;k<9;k++)
        {
            if(board[i][k]==c)return false;
            if(board[k][j]==c)return false;
            if(board[(i/3)*3+k/3][(j/3)*3+k%3]==c)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
         for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                for(char c='1';c<='9';c++)
                {
                    if(issafe(i,j,c,board))
                    {
                        board[i][j]=c;
                        if(solve(board))return true;
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
   solve(board);
   
    }
};