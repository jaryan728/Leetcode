class Solution {
public:
    string reverseParentheses(string s) {
    string ans="";
    stack<int>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==')')
        {
    
       int j= st.top();
       st.pop();
        
        

       reverse(s.begin()+j+1,s.begin()+i);
    
        }

        else if(s[i]=='(')
        st.push(i);
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