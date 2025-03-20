class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> mpp;
        int n = s.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (mpp.find(s[j]) != mpp.end()) {
                // i should be not in the discarded substring
                i = max(mpp[s[j]] + 1, i);
            }
            ans = max(ans, j - i + 1);

            mpp[s[j]] = j;
        }

        return ans;
    }
};