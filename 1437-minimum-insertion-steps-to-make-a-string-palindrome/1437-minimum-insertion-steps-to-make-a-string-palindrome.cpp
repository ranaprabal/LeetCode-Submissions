class Solution {
public:
    int minInsertions(string str1) {
        string str2=str1;
        reverse(str1.begin(),str1.end());
        int n=str1.size();
        int t[n+1][n+1];
        for(int i=0;i<n+1;i++) {t[i][0]=0;t[0][i]=0;}
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(str1[i-1]==str2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return n-t[n][n]; 
    }
};