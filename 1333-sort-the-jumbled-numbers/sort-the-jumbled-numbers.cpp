bool comp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first==p2.first)
    {
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}
class Solution {
public:

   
 int mapped(int r, vector<int>& mapping) {
    int ans = 0;

    if (r == 0) return mapping[0];

    vector<int> digits; 
    while (r != 0) {
        int digit = r % 10; 
        digits.push_back(mapping[digit]); 
        r=r/10;
    }

    for (int i = digits.size() - 1; i >= 0; --i) {
        ans = ans * 10 + digits[i];
    }

    return ans;
}

   vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    vector<pair<int, int>> p(n);
    for (int i = 0; i < nums.size(); i++) {
        int m = nums[i];
        int k = mapped(m, mapping);
        p[i].first = k;
        p[i].second = i;
    }
    sort(p.begin(), p.end(), comp);
    for (int i = 0; i < p.size(); i++) {
        ans[i] = nums[p[i].second];
    }
    return ans;
}

};