class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    if(nums.size()<=1)return nums.size();
    int ans=1,c=1;
    set<int>st(nums.begin(),nums.end());
    auto it=st.begin();
    int top=*it;
    if(it!=st.end())it++;
    for(;it!=st.end();it++)
    {
        if(*it==top+1)
        {
            c++;
            ans=max(c,ans);
        }
        else c=1;
                    top=*it;

    }
  
    
    return ans;
    }
};