class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
    long long sum=0;
    vector<long long >sub;
    for(int i=0;i<n;i++)
    {
        long long  s=0;
        for(int j=i;j<n;j++) 
        {
            s+=nums[j];
            s=s%(1000000000+7);
                    sub.push_back(s);

        }   
    }
    sort(sub.begin(),sub.end());
    for(int i=left-1;i<right;i++)
    {
        sum=(sum+sub[i])%(1000000000+7);  
  }
   return (int)sum;
    }
};