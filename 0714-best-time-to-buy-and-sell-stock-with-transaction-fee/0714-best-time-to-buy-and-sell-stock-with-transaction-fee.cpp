int dp[50001][2];
class Solution {
public:
    int rec(int n,bool buy,vector<int>&a,int &fee){
        if(n==a.size()) return dp[n][buy] = 0;
        if(dp[n][buy] != -1) return dp[n][buy];
        if(buy){
            return dp[n][buy] =max(-a[n]-fee+rec(n+1,0,a,fee),rec(n+1,1,a,fee));
        }
        else
        return dp[n][buy] =max(a[n]+rec(n+1,1,a,fee),rec(n+1,0,a,fee));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,1,prices,fee);
    }
};