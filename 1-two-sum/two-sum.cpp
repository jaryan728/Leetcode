class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     vector<int>ans;
     map<int,int>mpp;
     int n=nums.size();
     for(int i=0;i<n;i++)
     {
        int rem=target-nums[i];
        if(mpp.find(rem)!=mpp.end())
        {
            ans.push_back(i);
            ans.push_back(mpp[rem]);
        }
        mpp[nums[i]]=i;
     }
     return ans;
    }
};