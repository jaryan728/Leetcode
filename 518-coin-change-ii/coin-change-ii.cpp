class Solution {
public:
    int change(int amount, vector<int>& coins) {
     vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
    vector<int>curr(amount+1,0),prev(amount+1,0);
    if(amount==0)return 1;
    // int ans=solve(coins.size()-1,coins,amount,dp);
    // if(ans==1e9)return -1;
    for(int i=0;i<=amount;i++)
    {if(i%coins[0]==0)prev[i]=1;
    else prev[i]=0;
    }
    for(int i=1;i<coins.size();i++)
    {
        for(int j=0;j<=amount;j++)
        {
             int tk=0;
        if(j>=coins[i])
        {
            tk=curr[j-coins[i]];
        }
        int nt=prev[j];
         curr[j]=tk+nt;
        }
        prev=curr;
    }
    int ans= prev[amount];
    if(ans==1e9)return -1;
    return ans;
    }
    
};