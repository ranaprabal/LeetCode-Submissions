class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        int count[n][26];
        memset(count,0,sizeof(count));
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(auto &it:words[i]){
                count[i][it-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            int maxx = INT_MAX;
            for(int j=0;j<n;j++){
                maxx = min(maxx,count[j][i]);
            }
            while(maxx--){
                string temp = "";
                temp += char(i+'a');
                ans.push_back(temp);
            }
        }
        return ans;
    }
};