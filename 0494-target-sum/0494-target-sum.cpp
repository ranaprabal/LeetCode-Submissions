class Solution {
public:
    
    int rec(int &ans,vector<int>&nums,int sum,int n,int target)
    {
        if(n==0 && sum==target)
        {
            return 1; 
        }
        if(n==0) return 0;
        int sum1=sum-nums[n-1];
        sum=sum+nums[n-1];
        return rec(ans,nums,sum1,n-1,target)+rec(ans,nums,sum,n-1,target);
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        int ans=0;
        
        return rec(ans,nums,sum,n,target);
    }
};