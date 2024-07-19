class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& m) {
      vector<int>ans;
    for(int i=0;i<m.size();i++)
    {
        int mini=INT_MAX;
        int ind=-1;
        for(int j=0;j<m[0].size();j++)
        {
            if(m[i][j]<mini)
            {
                mini=m[i][j];
                ind=j;
            }
        }
        m[i][ind]*=-1;
    }
 
    for(int i=0;i<m[0].size();i++)
    {
        int maxi=-1,ind=-1;
        for(int j=0;j<m.size();j++)
        {
            if(abs(m[j][i])>maxi)
            {
                maxi=abs(m[j][i]);
                ind=j;
            }
        }
        if(m[ind][i]<0)ans.push_back(maxi);
    }
    return ans;
    }
};