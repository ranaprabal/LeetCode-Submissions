class Solution {
public:
  
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum%2) return false;
    int n=nums.size();
    sum/=2;
    bool t[n+1][sum+1];
    memset(t,false,sizeof(t));
    for(int i=0;i<n+1;i++) t[i][0]=true;
    for(int i=1;i<n+1;i++)
    {
      for(int j=1;j<sum+1;j++)
      {
        if(j>=nums[i-1])
        {
          t[i][j] = (t[i-1][j-nums[i-1]] || t[i-1][j]);
        }
        else t[i][j] = t[i-1][j];
      }
    }
    return t[n][sum];
  }

};