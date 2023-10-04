static int dp[30001][2];
class Solution {
public:
    int rec(int n,bool buy,vector<int>&a){
        if(n==a.size()) return dp[n][buy] = 0;
        if(dp[n][buy]!=-1) return dp[n][buy]; 
        if(buy){
            return dp[n][buy] = max( -a[n] + rec(n+1,0,a) , rec(n+1,1,a));
        }
        else{
            return dp[n][buy] = max(a[n]+rec(n+1,1,a),rec(n+1,0,a));
        }
    }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int dp[n+1][2];
        dp[n][0]=0,dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j){
                    dp[i][j]=max(-a[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                    dp[i][j]=max(a[i]+dp[i+1][1],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};