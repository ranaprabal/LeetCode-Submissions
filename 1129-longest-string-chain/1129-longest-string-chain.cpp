bool cmp(const string lhs, const string rhs){
    return lhs.length() < rhs.length();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int>length(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                bool found=false;
                if(words[i].size()==words[j].size()+1){
                    for(int p=0;p<words[i].size();p++){
                        if(words[i].substr(0,p)+words[i].substr(p+1)==words[j]){
                            found=true;
                            break;
                        }
                    }
                }
                if(found){
                    length[i]=max(length[i],length[j]+1);
                }
            }
        }
        return *max_element(length.begin(),length.end());

        
    }
};