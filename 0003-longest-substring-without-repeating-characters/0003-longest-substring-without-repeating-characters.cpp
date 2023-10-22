class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>a;
        int n=s.size();
        int curr =0,maxcount=0;
        int j=0,i=0;
        while(j<n && i<n){
            // cout<<j<<"   "<<i<<endl;
            // for(auto &it:a) cout<<it.first<<" "<<it.second<<endl;
            if(a.find(s[j])==a.end()){
                a[s[j]]=j;
                j++;
            }
            else{
                while(i<=a[s[j]]){
                    a.erase(s[i]);
                    i++;
                }
                a[s[j]]=j;
                j++;
            }
            maxcount=max(maxcount,j-i);
        }
        return maxcount;
    }
};