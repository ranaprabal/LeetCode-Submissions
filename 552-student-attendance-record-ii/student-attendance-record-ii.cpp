class Solution {
public:
    int MOD = 1e9 +7;
    int rec(int i, int a, int l, int n,vector<vector<vector<int>>>&dp) {
        if(dp[i][a][l] !=-1) return dp[i][a][l];
        if (i == n) {
            return dp[i][a][l] = 1 + (a > 0) + (l > 0);
        }
        if (a && l) {
            return dp[i][a][l] = ((rec(i + 1, a - 1, 2, n ,dp) + rec(i + 1, a, l - 1, n ,dp))%MOD +
                   rec(i + 1, a, 2, n ,dp))%MOD;
        }
        if (a) {
            return dp[i][a][l] = (rec(i + 1, a - 1, 2, n ,dp) + rec(i + 1, a, 2, n ,dp))%MOD;
        }
        if (l)
            return dp[i][a][l] = (rec(i + 1, a, 2, n ,dp) + rec(i + 1, a, l - 1, n ,dp))%MOD;
        return dp[i][a][l] = rec(i + 1, a, 2, n ,dp);
    }

    int checkRecord(int n) { 
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return rec(1, 1, 2, n ,dp); }
};