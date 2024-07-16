class Solution {
public:
    int trap(vector<int>& h) {
    int ans=0,n=h.size();
    vector<int>left(n);
    vector<int>right(n);
    int max1=0,max2=0;
    for(int i=0;i<n;i++)
    {
        max1=max(max1,h[i]);
        left[i]=max1;
    }
      for(int i=n-1;i>=0;i--)
    {
        max2=max(max2,h[i]);
        right[i]=max2;
    }
    for(int i=0;i<n;i++)
    {
        ans+=min(left[i],right[i])-h[i];
    }
    return ans;
    }
};