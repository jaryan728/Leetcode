class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int>a;
    int m=matrix.size(),n=matrix[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            a.push_back(matrix[i][j]);
        }
    }
    int i=0,j=a.size()-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(a[mid]==target)return true;
        else if(a[mid]<target)i=mid+1;
        else j=mid-1;
    }
    return false;
    }
};