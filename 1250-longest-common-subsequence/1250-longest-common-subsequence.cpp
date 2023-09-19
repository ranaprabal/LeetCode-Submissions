int static t[1001][1001];
class Solution {
public:
    int rec(string &text1,string &text2,int n,int m){
        if(t[n][m]!=-1){
            return t[n][m];
        }
        if(n==0 || m==0){
            return 0;
        }
        if(text1[n-1]==text2[m-1]){
            t[n][m]=1+rec(text1,text2,n-1,m-1);
        }
        else{
            t[n][m]=max(rec(text1,text2,n-1,m),rec(text1,text2,n,m-1));
        }
        return t[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        int n = text1.size();
        int m = text2.size();
        return rec(text1,text2,n,m);
    }
};