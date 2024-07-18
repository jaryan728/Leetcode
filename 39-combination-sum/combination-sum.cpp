class Solution {
public:
    void find(int i,     vector<vector<int>>&ans,vector<int>c,int t,int s,vector<int>temp)
    {
        if(s>t)return;
        if(i==c.size())
        {
            if(s==t)
            ans.push_back(temp);
            return ;
        }
        s+=c[i];
        temp.push_back(c[i]);
        find(i,ans,c,t,s,temp);
        s-=c[i];
        temp.pop_back();
        find(i+1,ans,c,t,s,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<vector<int>>ans;
     vector<int>temp;
     find(0,ans,candidates,target,0,temp);
     return ans;
    }
};