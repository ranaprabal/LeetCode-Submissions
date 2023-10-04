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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> x;
        for (int num : nums) {
            auto it = lower_bound(x.begin(), x.end(), num);
            if (it == x.end()) {
                x.push_back(num);
            } else {
                *it = num;
            }
        }
        return x.size();
        // int n=nums.size();
        // memset(dp,-1,sizeof(dp));
        // return rec(n,n,nums);
    }
};