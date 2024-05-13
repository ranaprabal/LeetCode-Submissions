class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    grid[i][j]=grid[i][j]^1;
                }   
            }
        }
        for(int i=1;i<m;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                count +=grid[j][i];
            }
            if(2*count<n){
                for(int j=0;j<n;j++){
                    grid[j][i]=grid[j][i]^1;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int temp = 1;
            int number =0;
            for(int j=m-1;j>=0;j--){
                number += grid[i][j]*temp;
                temp = temp*2;
            }
            ans+=number;
        }
        return ans;
    }
};