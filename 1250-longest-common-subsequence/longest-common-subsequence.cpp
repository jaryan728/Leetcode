class Solution {
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>> dp) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
        }
        return dp[i][j] = max(solve(i - 1, j, s1, s2, dp),
                              solve(i, j - 1, s1, s2, dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        int m = s1.size();
        int n = s2.size();
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <=n; j++) {
                
                    if (s1[i-1] == s2[j-1]) {
                        dp[i][j] = 1 + dp[i -1 ][ j - 1] ;
                    } else {
                       
                            
                      
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                
            }
        }
        // return solve(text1.size()-1,text2.size()-1,text1,text2,dp);
        return dp[m][n];
    }
};