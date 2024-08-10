class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,int& ans, vector<vector<int>>&dp)
    {
        if(i<0||j<0)return 0;

        if(i==0&&j==0)
        {
            
            return 1;
        }
        else if(dp[i][j]!=-1)return dp[i][j];
        else if(grid[i][j]==1)return 0;
        int l,r;
        if(grid[i][j]==0)
        {
        l= solve(i-1,j,grid,ans,dp);
        r= solve(i,j-1,grid,ans,dp);
        }
        return dp[i][j]=l+r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int ans=0;
    int  m=grid.size();
    int n=grid[0].size();
    if(grid[0][0]==1)return 0;
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(m-1,n-1,grid,ans,dp);
    
    }
};