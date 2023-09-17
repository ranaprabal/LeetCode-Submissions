class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(target>sum) return 0;
        sum=sum-target;
        if(sum%2) return 0;
        sum/=2;
        int t[n+1][sum+1];
        for(int i=0;i<sum+1;i++) t[0][i]=0;
        for(int i=0;i<n+1;i++) t[i][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j>=nums[i-1])
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
    }
};