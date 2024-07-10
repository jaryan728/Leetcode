class Solution {
public:
    int minOperations(vector<string>& logs) {
    int cnt=0;
    for(int i=0;i<logs.size();i++)
    {
       if(isalpha(logs[i][0])||isdigit(logs[i][0]))cnt++;
       else if(cnt!=0&&logs[i]=="../")cnt--;

    }
    if(cnt<0)return 0;
    return cnt;
    }
};