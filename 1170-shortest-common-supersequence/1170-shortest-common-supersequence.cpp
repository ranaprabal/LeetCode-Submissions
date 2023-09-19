class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int t[n+1][m+1];
        for(int i=0;i<n+1;i++) t[i][0]=0;
        for(int i=0;i<m+1;i++) t[0][i]=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1[i-1]==str2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        string ans="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans=str1[i-1]+ans;
                j--;i--;
            }
            else if(t[i-1][j]<t[i][j-1]){
                ans=str2[j-1]+ans;
                j--;
            }
            else{
                ans=str1[i-1]+ans;
                i--;
            }
        }
        if(i==0){
            for(int p=j-1;p>=0;p--){
                ans=str2[p]+ans;
            }
        }
        else{
           for(int p=i-1;p>=0;p--){
                ans=str1[p]+ans;
            } 
        }
        return ans;
    }
};