class Solution {
public:
    int findMin(vector<int>& a) {
    int low=0,high=a.size()-1;
        if(a[low]<=a[high])return a[low];

    while(low<high)
    {
        int mid=(low+(high-low)/2);
        if(a[mid]>=a[0])low=mid+1;
        else
        high=mid;
    }   
    return a[low];
    }
};