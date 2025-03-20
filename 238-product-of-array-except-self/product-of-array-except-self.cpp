class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pf(n);
        pf[0]=1;
        vector<int> sf(n);
        sf[n-1]=1;

        for (int i = 1; i < n; i++) {
            pf[i]=pf[i-1]*nums[i-1];
        }
        for(int j=n-2;j>=0;j--)
        {
            sf[j]=sf[j+1]*nums[j+1];
        }
         for(int j=n-1;j>=0;j--)
        {
            ans[j]=sf[j]*pf[j];
        }
        return ans;
    }
};