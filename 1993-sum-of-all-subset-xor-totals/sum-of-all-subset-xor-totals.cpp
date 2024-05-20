class Solution {
public:

    void rec(int i,vector<int>&nums,int temp,int &ans){
        if(i==nums.size()){
            ans+=temp;
            return;
        }
        rec(i+1,nums,temp^nums[i],ans);
        rec(i+1,nums,temp,ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        rec(0,nums,0,ans);
        
        return ans;
    }
};