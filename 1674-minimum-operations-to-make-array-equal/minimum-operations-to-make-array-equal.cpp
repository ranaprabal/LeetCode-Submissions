class Solution {
public:
    int minOperations(int n) {
        if(n&1){
            return (n+1)*(n-1)/4;
        }
        else return (n*n)/4;
    }
};