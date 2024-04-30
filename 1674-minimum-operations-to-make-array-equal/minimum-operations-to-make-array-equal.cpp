class Solution {
public:
    int minOperations(int n) {
        return (n*n - (n&1))/4;
    }
};