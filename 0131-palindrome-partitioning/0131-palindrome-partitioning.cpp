class Solution {
public:
    bool isPali(string &s){
        int i=0,j=s.size();
        j--;
        while(i<j){
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
    void rec(vector<vector<string>>&ans,vector<string>op,string &s,int j){
        int n=op.size();
        if(j==s.size()){
            if(isPali(op[n-1])){
                ans.push_back(op);
            }
            return;
        }
        string temp = "";
        temp+=s[j];
        if(n==0){    
            op.push_back(temp);
            rec(ans,op,s,j+1);
            return;
        }
        else if(isPali(op[n-1])){
            vector<string>op2=op;
            op2.emplace_back(temp);
            op[n-1]+=s[j];
            rec(ans,op2,s,j+1);
            rec(ans,op,s,j+1);
        }
        else{
            op[n-1]+=s[j];
            rec(ans,op,s,j+1);
        }
        return;
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>>ans;
      rec(ans,{},s,0);
      return ans;  
    }
};