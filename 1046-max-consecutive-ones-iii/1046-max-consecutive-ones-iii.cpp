class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int zero=0,ans=0;
        while(j<nums.size()){
            if(nums[j]==0) zero++;
            j++;
            if(zero>k){
              while(nums[i]!=0){
                  i++;
              }
              i++;
              zero--;  
            }
            ans=max(ans,j-i); 
        }
        return ans;
    }
};