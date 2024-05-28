class Solution {
public:

    int equalSubstring(string s, string t, int maxCost) {
        int ans =0,n=s.length();
        int i=0,j=0;
        int cost = maxCost;
        while(j<n){
            while(j<n && cost>=abs(s[j]-t[j])){
                cost -= abs(s[j]-t[j]);
                j++;
            }
            ans = max(ans,j-i);
            while(i<=j && cost<abs(s[j]-t[j])){
                cost +=abs(s[i]-t[i]);
                i++;
            }
        }
        return ans;
    }
};