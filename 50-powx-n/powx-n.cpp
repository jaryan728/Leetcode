class Solution {
public:
    double solve(double x,int n)
    {   if(n==0)return 1;
        if(n==1)return x;
        double half=solve(x,n/2);
        if(n%2!=0)
        {
            return x*half*half;

        }
        return half*half;

    }
    double myPow(double x, int n) {
    if(n==0)return 1;
    if(x==1||x==0)return x;
    double ans=solve(x,abs(n)); 
    if(n<0)return 1/ans;
    return ans;
    }
};