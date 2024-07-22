class Solution {
public:
    void find(int i, vector<int>nums,     vector<vector<int>>&ans,vector<int>temp)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[j],nums[i]);
            find(i+1,nums,ans,temp);

              swap(nums[j],nums[i]);
        }   
    }
    vector<vector<int>> permute(vector<int>& nums) {
     vector<vector<int>>ans;
     vector<int>temp;

    find(0,nums,ans,temp);
    return ans;
}};