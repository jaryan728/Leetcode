class Solution {
public:
    // int solve(int i,vector<int>& coins, int amount,vector<vector<int>>dp)
    // {
        
    //     if(i==0)
    //     {
    //         if(amount%coins[0]==0)return amount/coins[0];
    //         return 1e9;
    //     }
    //     if(dp[i][amount]!=-1)return dp[i][amount];
    //     int tk=1e9;
    //     if(amount>=coins[i])
    //     {
    //         tk=1+solve(i,coins,amount-coins[i],dp);
    //     }
    //     int nt=0+solve(i-1,coins,amount,dp);
    //     return dp[i][amount]=min(tk,nt);
    // }
    int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
    vector<int>curr(amount+1,0),prev(amount+1,0);
    if(amount==0)return 0;
    // int ans=solve(coins.size()-1,coins,amount,dp);
    // if(ans==1e9)return -1;
    for(int i=0;i<=amount;i++)
    {if(i%coins[0]==0)prev[i]=i/coins[0];
    else prev[i]=1e9;
    }
    for(int i=1;i<coins.size();i++)
    {
        for(int j=0;j<=amount;j++)
        {
             int tk=1e9;
        if(j>=coins[i])
        {
            tk=1+curr[j-coins[i]];
        }
        int nt=prev[j];
         curr[j]=min(tk,nt);
        }
        prev=curr;
    }
    int ans= prev[amount];
    if(ans==1e9)return -1;
    return ans;
    }
};