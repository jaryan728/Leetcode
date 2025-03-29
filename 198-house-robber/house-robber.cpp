class Solution {
public:
    int solve(int i,vector<int>nums,vector<int>&ans)
    {
        if(i>=nums.size())return 0;
        if(ans[i]!=-1)return ans[i];
        int pk=0;
        pk=nums[i]+solve(i+2,nums,ans);
        int nt=0;
        nt=solve(i+1,nums,ans);
     return   ans[i]= max(pk,nt);
    }
    int rob(vector<int>& nums) {
    vector<int>dp(nums.size(),-1);
   return solve(0,nums,dp);

    }
};