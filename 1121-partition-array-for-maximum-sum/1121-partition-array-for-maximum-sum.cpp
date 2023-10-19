int dp[501];
class Solution {
public:
    int rec(vector<int>&a,int &k,int i){
        int n=a.size();
        if(dp[i]!=-1) return dp[i];
        if(i>n-k){
            if(i==n) return dp[i] = 0;
            int maxx = *max_element(a.begin()+i,a.end());
            return dp[i] = (n-i)*maxx;
        }
        int ans = INT_MIN;
        for(int p=i;p<i+k;p++){
            int maxx = *max_element(a.begin()+i,a.begin()+p+1);
            int sum = maxx*(p-i+1);
            int next = 0;
            if(dp[p+1]!=-1) next = dp[p+1];
            else dp[p+1] = next = rec(a,k,p+1);
            ans = max(ans,sum + next);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(arr,k,0);
    }
};