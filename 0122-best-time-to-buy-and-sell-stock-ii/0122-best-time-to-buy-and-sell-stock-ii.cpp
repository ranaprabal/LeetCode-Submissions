static int dp[30001][2];
class Solution {
public:
    int rec(int i,bool buy,vector<int>&a){
        if(i==a.size()) return dp[i][buy] = 0;
        if(dp[i][buy]!=-1) return dp[i][buy]; 
        if(buy){
            return dp[i][buy] = max( -a[i] + rec(i+1,0,a) , rec(i+1,1,a));
        }
        else{
            return dp[i][buy] = max(a[i]+rec(i+1,1,a),rec(i+1,0,a));
        }
    }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,1,a);
    }
};