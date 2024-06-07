class Solution {
public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        string ans ="";
        unordered_set<string>dict;
        for(auto &it:dictionary) dict.insert(it);
        string temp="";
        bool found = false;
        for(auto &it:sentence){
            if(it==' '){
                if(!found){
                    ans+=temp;
                    ans+=" ";
                }
                found=false;
                temp="";
                continue;
            }
            if(found) continue;
            temp+=it;
            if(dict.find(temp)!=dict.end()){
                ans+=temp;
                ans+=" ";
                found = true;
            }  
        }
        int n = ans.length();
        if(dict.find(temp)==dict.end()){
            ans+=temp;
        }
        else ans  = ans.substr(0,n-1);
        return ans;
    }
};