class Solution {
public:
    int passThePillow(int n, int time) {
        time %=2*(n-1);
        bool odd = (time/(n-1))&1;
        time %=(n-1);
        int ans = abs((n)*odd - time );
        return ans + (odd==0);
    }
};