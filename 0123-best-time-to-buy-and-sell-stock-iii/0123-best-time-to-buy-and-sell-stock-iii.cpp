int dp[100001][2][3];
class Solution {
public:
    int rec(int n,bool buy,int count,vector<int>&a){
        if(count==0 || n==a.size()) return dp[n][buy][count] = 0;
        if(dp[n][buy][count]!=-1) return dp[n][buy][count];
        if(buy){
            return dp[n][buy][count] = max(-a[n]+rec(n+1,0,count,a),rec(n+1,1,count,a));
        }
        else{
            return dp[n][buy][count] = max(a[n]+rec(n+1,1,count-1,a),rec(n+1,0,count,a));
        }
    }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,1,2,a);
    }
};