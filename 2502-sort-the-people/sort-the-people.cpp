class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<int,int>>p;
    for(int i=0;i<names.size();i++)
    {
        p.push_back({heights[i],i});
    }
    vector<string>ans;
    sort(p.begin(),p.end());
    for(int i=p.size()-1;i>=0;i--)
    {
        ans.push_back(names[p[i].second]);
    }
    return ans;
    }
};