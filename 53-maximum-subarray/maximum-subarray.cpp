class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int ans=INT_MIN;
    int s=0,n=nums.size();
    for(int i=0;i<n;i++)
    {
        s+=nums[i];
        ans=max(ans,s);
        if(s<0)s=0;
    }
    return ans;
    }
};