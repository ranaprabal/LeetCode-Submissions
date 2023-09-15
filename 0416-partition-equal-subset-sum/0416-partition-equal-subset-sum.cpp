class Solution {
public:
  bool rec(int t[201][20001],vector<int>&nums,int n,int sum)
  {
    if(t[n][sum]!=-1) return t[n][sum];
    if(sum==0)
    {
      t[n][sum]=1;
      return true;
    }
    if(n==0)
    {
      t[n][sum]=0;
      return false;
    }
    if(sum>=nums[n-1])
    {
      t[n][sum]=(rec(t,nums,n-1,sum) || rec(t,nums,n-1,sum-nums[n-1]));
      return t[n][sum];
    }
    else{

      t[n][sum]= rec(t,nums,n-1,sum);
      return t[n][sum];
    } 
  }


  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum%2) return false;
    int t[201][20001];
    memset(t,-1,sizeof(t));
    return rec(t,nums,nums.size(),sum/2);
  }

};