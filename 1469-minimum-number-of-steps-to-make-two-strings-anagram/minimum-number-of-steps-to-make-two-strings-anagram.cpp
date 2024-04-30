class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>a1(26,0);
        vector<int>a2(26,0);
        for(int i=0;i<s.size();i++){
            a1[s[i]-'a']++;
            a2[t[i]-'a']++;
        }
        int sum =0;
        for(int i=0;i<26;i++){
            sum +=abs(a1[i]-a2[i]);
        }
        return sum/2;
    }
};