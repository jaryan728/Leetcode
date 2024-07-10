class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
             if(i>0&&nums[i]==nums[i-1])continue;

            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int s=nums[i]+nums[j]+nums[k];
                if(s<0)
                {
                    j++;
                }
                else if(s>0)
                {
                    k--;
                }
                else
                {
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                 while(k>j&&nums[k]==nums[k+1])k--;
                while(j<k&&nums[j]==nums[j-1])j++;

                }
              
            }
        } 
        return ans;
    }
};