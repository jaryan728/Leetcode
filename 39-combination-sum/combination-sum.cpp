class Solution {
public:
    void find(int i, vector<int>& c, int target, vector<vector<int>>& ans,
              vector<int> temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        } 
        else if (i == c.size() || target < 0)
            return;
        temp.push_back(c[i]);
        find(i, c, target - c[i], ans, temp);
        temp.pop_back();
        find(i + 1, c, target, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        find(0, candidates, target, ans, temp);
        return ans;
    }
};