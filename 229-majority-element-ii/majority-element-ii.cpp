class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int maj1=0,maj2=0,c1=0,c2=0;
    for(int i=0;i<nums.size();i++)
    {
        if(c1==0&&maj2!=nums[i])
        {
            maj1=nums[i];
        }
        else if(c2==0&&maj1!=nums[i])maj2=nums[i];
        if(maj1==nums[i])c1++;
       else  if(maj2==nums[i])c2++;
        else
        {
            c1--;
            c2--;
        }


    }
    int t1=0,t2=0;
    for(int i=0;i<nums.size();i++)
    {
        if(maj1==nums[i])t1++;
        else if(maj2==nums[i])t2++;
    }
    
    cout<<maj1<<maj2;
    vector<int>ans;
    if(t1>nums.size()/3)ans.push_back(maj1);
      if(t2>nums.size()/3)ans.push_back(maj2);
    return ans;

    }
};