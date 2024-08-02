class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        int cnt =0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt++;
        }
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        n = nums.size();
        int curr = 0;
        for(int i=0;i<cnt;i++){
            if(nums[i]==0) curr++;
        }
        int i = 0;
        int ans = cnt - curr;
        for(int j=cnt;j<n;j++){
            // cout<<j<<" "<<cnt<<" "<<curr<<endl;
            if(nums[j]==0){
                curr++;
                if(nums[i]==0) curr--;
            }
            else{
                if(nums[i]==0) curr--;
            }

                ans = min(ans,cnt-curr);
                i++;
        }
        return ans;
    }
};