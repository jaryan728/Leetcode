class Solution {
public:
    void find(int i,vector<int>&nums,      set<vector<int>>&st,vector<int>temp)
    {
        if(i==nums.size())
        {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        find(i+1,nums,st,temp);
        temp.pop_back();
                find(i+1,nums,st,temp);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>>ans;
      set<vector<int>>st;
      vector<int>temp;
      sort(nums.begin(),nums.end());
      find(0,nums,st,temp);   
      for(auto it :st)ans.push_back(it);
      return ans;
    }
};