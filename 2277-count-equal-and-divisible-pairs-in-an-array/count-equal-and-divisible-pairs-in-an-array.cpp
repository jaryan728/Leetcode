class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
    map<int,vector<int>>mpp;
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
       if(mpp.find(nums[i])!=mpp.end())
       {
        for(int ind:mpp[nums[i]])
        {
            if((ind*i)%k==0)ans++;
        }
       }
       mpp[nums[i]].push_back(i);
    }
    return ans;
    }
};