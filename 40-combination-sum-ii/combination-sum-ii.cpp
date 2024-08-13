class Solution {
public:
    void find(int i,vector<int>temp,vector<int>& c,int target, vector<vector<int>>&ans)
    {
             if(target==0)
            {
            ans.push_back(temp);
            
            return;
        }
        if(i>=c.size()||target<0)return;
        
      
       
        temp.push_back(c[i]);
        find(i+1,temp,c,target-c[i],ans);
        temp.pop_back();
        while(i+1<c.size()&&c[i]==c[i+1])i++;
        find(i+1,temp,c,target,ans);

        
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {  
      vector<vector<int>>ans;
      vector<int>temp;
      sort(c.begin(),c.end());
      find(0,temp,c,target,ans);
      return ans;
    }
};