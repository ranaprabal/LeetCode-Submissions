static int dp[2501][2501];
class Solution {
public:
    int rec(int n,int prev,vector<int>&a){
        if(n<=0) return 0;
        if(dp[n][prev]!=-1) return dp[n][prev];
        if(prev==a.size()){
            return dp[n][prev] = max(1+rec(n-1,n-1,a),rec(n-1,prev,a));
        }
        else if(a[prev]>a[n-1]){
            return dp[n][prev] = max(1+rec(n-1,n-1,a),rec(n-1,prev,a));
        } 
        return dp[n][prev] = rec(n-1,prev,a);
    }
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        int dp[n+1][n+1];
	for(int i=0;i<n+1;i++) dp[0][i]=0;
	for(int i=1;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			if(j==n){
			    dp[i][j] = max(1+dp[i-1][i-1],dp[i-1][j]);
			}
			else if(a[j]>a[i-1]){
			    dp[i][j]=max(1+dp[i-1][i-1],dp[i-1][j]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
    return dp[n][n];
        // vector<int> x;
        // for (int num : nums) {
        //     auto it = lower_bound(x.begin(), x.end(), num);
        //     if (it == x.end()) {
        //         x.push_back(num);
        //     } else {
        //         *it = num;
        //     }
        // }
        // return x.size();
        // int n=nums.size();
        // memset(dp,-1,sizeof(dp));
        // return rec(n,n,nums);
    }
};