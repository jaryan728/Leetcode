class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int ans=1e9;
    vector<vector<int>>dp(n,vector<int>(n,-1));

    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
        if(i==0)dp[i][j]=matrix[i][j];
        else
        {
            int l=1e9,r=1e9,d=1e9;
            if(i-1>=0&&j-1>=0)l= matrix[i][j]+dp[i-1][j-1];
            if(i-1>=0&&j+1<n)r= matrix[i][j]+dp[i-1][j+1];
            if(i-1>=0)d= matrix[i][j]+dp[i-1][j];
            dp[i][j]=min({l,r,d});



        }
       }
    }
    for(int i=0;i<n;i++)ans=min(ans,dp[n-1][i]);
    return ans;
    }
};