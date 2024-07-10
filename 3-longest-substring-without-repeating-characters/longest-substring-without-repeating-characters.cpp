class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    map<char,int>mpp;
    string t="";
    int j=0,ans=0;
    for(int i=0;i<s.size();i++)
    {

        if(mpp.find(s[i])!=mpp.end())
        {
           
                j=max(j,mpp[s[i]]+1);
                
        

            
        }
    ans=max(i-j+1,ans);

        mpp[s[i]]=i;
    }
    return ans;
    }
};