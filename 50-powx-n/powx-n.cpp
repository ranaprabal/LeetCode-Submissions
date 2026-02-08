class Solution {
public:
    double myPow(double x, long n) {
        if(n==0) return 1;
        if (n<0) return myPow(1/x, -1*n);
        if (n==1) return x;
        if (n%2) return x*myPow(x*x,n/2);
        else return myPow(x*x,n/2);
    }
};