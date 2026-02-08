class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()<=2) {
            if(nums.size()==2 && nums[0]==nums[1]) return {nums[0]};
            return nums;}
        int cnt1=0, cnt2=0;
        int ele1=nums[0], ele2=nums[1];
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1){ 
                cnt1++;
            } else if(nums[i]==ele2){
                cnt2++;
            } else if(cnt1==0 && nums[i]!=ele1){
                cnt1++;
                ele1 = nums[i];
            } else if(cnt2==0 && nums[i]!=ele2){
                cnt2++;
                ele2 = nums[i];
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(auto &x:nums){
            if(x==ele1) cnt1++;
            else if(x==ele2) cnt2++;
        }
        if(cnt1>nums.size()/3 && cnt2>nums.size()/3){
            return {ele1, ele2};
        } else if(cnt1>nums.size()/3){
            return {ele1};
        } else if(cnt2>nums.size()/3) return {ele2};
        return  {};
    }
};