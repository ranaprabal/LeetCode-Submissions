int dp[5001][2];
class Solution {
public:
    int rec(int n,bool buy,vector<int>&a){
        if(n>=a.size()) return dp[n][buy] = 0;
        if(dp[n][buy]!=-1) return dp[n][buy];
        if(buy){
            return dp[n][buy] = max(-a[n]+rec(n+1,0,a),rec(n+1,1,a));
        }
        else
        return dp[n][buy] = max(a[n]+rec(n+2,1,a),rec(n+1,0,a));
    }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,1,a);
    }
};