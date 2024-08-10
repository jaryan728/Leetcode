class Solution {
public:
    bool bfs(int i, int c,vector<int>&color,vector<vector<int>>& graph)
    {
        color[i]=c;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {

            int n=q.front();
            q.pop();
            for(int j=0;j<graph[n].size();j++)
            {
                if(color[graph[n][j]]==-1)
                {
                    color[graph[n][j]]=!color[n];
                    q.push(graph[n][j]);
                }
                else if(color[graph[n][j]]!=-1&&color[graph[n][j]]==color[n])
            return false;

                
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    bool f;
    vector<int>color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
{
if(!bfs(i,0,color,graph))return false;
}     
    }
    return 1;
    }
};