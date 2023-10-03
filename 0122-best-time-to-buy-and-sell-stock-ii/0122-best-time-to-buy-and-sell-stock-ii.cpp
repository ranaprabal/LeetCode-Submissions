class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int ans =0,prev=a[0];
        for(int i=0;i<n;i++){
            if(0<a[i]-prev){
                ans+=a[i]-prev;
                prev=a[i];
            }
            else prev=a[i];
        }
        return ans;
    }
};