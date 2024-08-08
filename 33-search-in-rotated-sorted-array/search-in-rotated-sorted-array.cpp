class Solution {
public:
    int pivot(vector<int>& a) {
    int low=0,high=a.size()-1;
        if(a[low]<=a[high])return low;

    while(low<high)
    {
        int mid=(low+(high-low)/2);
        if(a[mid]>=a[0])low=mid+1;
        else
        high=mid;
    }   
    return low;
    }
    int bs(int low,int high,vector<int>a,int k)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(a[mid]==k)return mid;
            if(a[mid]<k)low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int search(vector<int>& a, int target) {
    int ans=-1;
    int low=0,high=a.size()-1;
    int ind=pivot(a);
    ans =bs(low,ind-1,a,target);
    if(ans==-1)ans=bs(ind,high,a,target);
    return ans;

    }
};