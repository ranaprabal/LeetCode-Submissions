class Solution {
public:
    int rec(vector<vector<int>>&t,vector<int>&nums,int n,int sum)
    {
        if(t[n][sum]!=-1) return t[n][sum];
        if(sum==0 && n==0)
        {
            t[n][sum]=1;
            return t[n][sum];
        }
        if(n==0)
        {
            t[n][sum]=0;
            return t[n][sum];
        }
        if(sum>=nums[n-1])
        {
            t[n][sum]=rec(t,nums,n-1,sum)+rec(t,nums,n-1,sum-nums[n-1]);
            return t[n][sum];
        }
        else{
            t[n][sum]=rec(t,nums,n-1,sum);
            return t[n][sum];
        }

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>totalsum) return abs(target)==totalsum;
        target=totalsum-abs(target);
        if(target%2) return 0;
        target/=2;
        vector<vector<int>>t(n+1,vector<int>(target+1,0));
        for(int i=0;i<n+1;i++)
            for(int j=0;j<target+1;j++)
                t[i][j]=-1;
        rec(t,nums,n,target);
        return t[n][target];


    }
};