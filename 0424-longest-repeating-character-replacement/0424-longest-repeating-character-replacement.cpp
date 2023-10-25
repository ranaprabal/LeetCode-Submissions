class Solution {
public:
    int characterReplacement(string s, int k) {
        int curr=0,n=s.size(),i=0,j=0,ans=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[s[j]]++;
            curr=max(curr,mp[s[j]]);
            j++;
            if(k<j-i-curr){
                mp[s[i]]--;
                i++;
            }else{
            ans=max(ans,j-i);
            }
        }
        return ans;
    }
};