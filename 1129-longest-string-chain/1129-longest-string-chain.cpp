bool cmp(const string lhs, const string rhs){
    return lhs.length() < rhs.length();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<string,int>mpp;
        int ans=1;
        sort(words.begin(),words.end(),cmp);
        for(auto &it:words)
        {
            mpp[it]=1;
            for(int i=0;i<it.size();i++){
                string temp=it.substr(0,i)+it.substr(i+1);
                if(mpp.find(temp)!=mpp.end()){
                    mpp[it]=max(mpp[it],mpp[temp]+1);
                }
            }
            ans=max(ans,mpp[it]);
        }
        return ans;
        
    }
};