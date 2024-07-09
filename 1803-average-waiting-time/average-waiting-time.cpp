class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
    int start=c[0][0]+c[0][1];
    double wait=start-c[0][0];
    for(int i=1;i<c.size();i++)
    {
        if(start<c[i][0])start=c[i][0];
        wait+=start-c[i][0]+c[i][1];
        start+=c[i][1];
    }
    return wait/c.size();
    }
};