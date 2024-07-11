class Solution {
public:
    string reverseParentheses(string s) {
    string ans="";
    stack<pair<char,int>>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==')')
        {
    
        while(!st.empty()&&st.top().first!='(')
        {
        st.pop();
        }
        
        

       reverse(s.begin()+st.top().second+1,s.begin()+i);
       st.pop();
        }

        else
        st.push({s[i],i});
    }
    for(char c:s)
    {
        if(c!='('&&c!=')')
        {
            ans+=c;
        }
    }

    return ans;
    }
};