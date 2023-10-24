class Solution {
public:
    int rec(vector<int>a,int goal){
        if(goal<0) return 0;
        int i=0,j=0,sum=0,ans=0;
        while(j<a.size()){
            sum+=a[j];
            while(sum>goal && i<=j){
                sum-=a[i++];
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return rec(nums,goal) - rec(nums,goal-1);
    }
};