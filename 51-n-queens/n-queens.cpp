class Solution {
public:
    bool issafe(int row,int col,vector<string>q)
    {
        //top;
        for(int k=0;k<row;k++)
        {
            if(q[k][col]=='Q')return false;
        }
        // top left dig
        int r=row-1,c=col-1;
        while(r>=0&&c>=0)
        {
            if(q[r][c]=='Q')return false;
            r--;c--;
        }

        //top right
        int r1=row-1,c1=col+1;
          while(r1>=0&&c1<q.size())
        {
            if(q[r1][c1]=='Q')return false;
            r1--;c1++;
        }
        return true;

    }
    void find(int i,     vector<vector<string>>&ans,     vector<string>q )
    {
        if(i>=q.size())
        {
            ans.push_back(q);
            return;
        }
        for(int j=0;j<q.size();j++)
        {
            if(q[i][j]=='.'&&issafe(i,j,q))
            {
                q[i][j]='Q';
                find(i+1,ans,q);
                q[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
     vector<vector<string>>ans;
          vector<string>q(n,string(n,'.'));
          find(0,ans,q);
        return ans;

    }
};