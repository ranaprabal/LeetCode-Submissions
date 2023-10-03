// map<string,int>dp;
class Solution {
    void rec(int count,int n,int sum,vector<vector<int>>&ans,vector<int>&v){
        if(n==0) {
            ans[count].push_back(sum);
            return;
        }
        if(n<0) return ;
        rec(count+1,n-1,sum+v[n-1],ans,v);
        rec(count,n-1,sum,ans,v);
    }
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>p1;
        vector<int>p2;
        for(int i=0;i<n;i++){
            if(i<n/2){
                p1.push_back(nums[i]);
            }
            else p2.push_back(nums[i]);
        } 
        vector<vector<int>>s1(n/2+1);
        vector<vector<int>>s2(n/2+1);
        rec(0,n/2,0,s1,p1);
        rec(0,n/2,0,s2,p2);
        for(int i=0;i<=n/2;i++){
            sort(s1[i].begin(),s1[i].end());
            sort(s2[i].begin(),s2[i].end());
        }
        int sum = accumulate(nums.begin(),nums.end(),0);
        int ans = INT_MAX;
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<s1[i].size();j++){
                int target = sum/2 - s1[i][j];
                int low =0,high = s2[n/2 - i].size();
                high--;
                while(low<high){
                    int mid = low + (high-low)/2;
                    if(s2[n/2 - i][mid]==target){
                        low=high=mid;
                        break;
                    }
                    else if(s2[n/2 - i][mid]<target){
                        low = mid+1;
                    }
                    else high =mid;
                }
                ans = min(ans, abs(sum - 2*(s1[i][j]+s2[n/2 - i][high])));
            }
        }
        return ans;

    }
};