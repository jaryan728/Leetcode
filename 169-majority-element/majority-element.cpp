class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int cnt=0,maj=0;
    for(int i=0;i<nums.size();i++)
    {
        if(cnt==0)
        maj=nums[i];
        if(maj==nums[i])cnt++;
        else if(maj!=nums[i])cnt--;
    }
    int c=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==maj)c++;
    }
    if(c>nums.size()/2)return maj;
    return -1;
    }
};