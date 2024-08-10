class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==triangle.size()-1)
        {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        // if(i>=triangle.size()||j>=triangle[i].size())return 1e9;
        int u,d;
        u=triangle[i][j]+solve(i+1,j,triangle,dp);
        d=triangle[i][j]+solve(i+1,j+1,triangle,dp);
        return dp[i][j]=min(u,d);


    }
    int minimumTotal(vector<vector<int>>& triangle) {
    int m=triangle.size();
    
    vector<vector<int>> dp(m,vector<int>(m,-1));
    return solve(0,0,triangle,dp);
    }
};