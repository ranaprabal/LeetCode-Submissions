class Solution {
public:
    void rec(string temp,string potentialAns,int i,string &s,unordered_set<string>&wordDict2,vector<string>&ans){
        if(i==s.size()){
            if(temp==""){
                ans.push_back(potentialAns);
            }
            return;
        }
        temp+=s[i];
        if(wordDict2.find(temp)!=wordDict2.end()){
            rec(temp,potentialAns,i+1,s,wordDict2,ans);
            if(potentialAns.size()) potentialAns+=" ";
            potentialAns+=temp;
            rec("",potentialAns,i+1,s,wordDict2,ans);
        }
        else{
            rec(temp,potentialAns,i+1,s,wordDict2,ans);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordDict2;
        for(auto &it:wordDict) wordDict2.insert(it);
        vector<string>ans;
        rec("","",0,s,wordDict2,ans);
        return ans;
    }
};