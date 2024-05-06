class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int t = part.size();
        while(true){
            n = s.size();
            bool ans = true;
            for(int i=0;i<n-t+1;i++){
                if(part==s.substr(i,t)){
                    s = s.substr(0,i) + s.substr(i+t);
                    ans = false;
                    break;
                }
            }
            if(ans) break;
        }
        return s;
    }
};