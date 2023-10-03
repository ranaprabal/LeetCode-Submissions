class Solution {
public:
    int coinChange(vector<int>& coins, int k) {
        int n=coins.size();
        int t[n+1][k+1];
        for(int i=0;i<k+1;i++) t[0][i]=INT_MAX-1;
        for(int i=0;i<n+1;i++) t[i][0]=0;
        for(int i=1;i<k+1;i++){
            if(i%coins[0]==0){
                t[1][i]=i/coins[0];
            }
            else t[1][i]=INT_MAX-1;
        }
        for(int i=2;i<n+1;i++){
            for(int j=1;j<k+1;j++){
                if(j>=coins[i-1]){
                    t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
                }
                else t[i][j]=t[i-1][j];
            }
        }
        if(t[n][k]<INT_MAX-1) return t[n][k];
        else return -1;
    }
};