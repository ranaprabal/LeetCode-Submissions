class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int magicGrid=0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 5) {
                    set<int> st;
                    int dx[4] = {0, -1, -1, -1};
                    int dy[4] = {-1, 0, -1, 1};
                    bool noSum = 1;
                    for (int x = 0; x < 4; x++) {
                        int X1 = i + dx[x];
                        int Y1 = j + dy[x];
                        int X2 = i - dx[x];
                        int Y2 = j - dy[x];
                        if ((grid[X1][Y1] - 5 == -(grid[X2][Y2] - 5)) && grid[X1][Y1]<=9 && grid[X2][Y2]<=9 && grid[X1][Y1]>0 && grid[X2][Y2]>0) {
                            st.insert(grid[X1][Y1]);
                            st.insert(grid[X2][Y2]);
                        } else
                            noSum = 0;
                    }
                    if(st.size()!=8) noSum =0;
                    if(noSum){
                        bool extrachecker = true;
                        int tempSum =0;
                        for(int x=0;x<3;x++){
                            tempSum+=grid[i-1+x][j-1];
                        }
                        if(tempSum!=15) extrachecker = false;
                        for(int x=0;x<3;x++){
                            tempSum+=grid[i-1+x][j+1];
                        }
                        if(tempSum!=30) extrachecker = false;
                        for(int x=0;x<3;x++){
                            tempSum+=grid[i+1][j-1+x];
                        }
                        if(tempSum!=45) extrachecker = false;
                        for(int x=0;x<3;x++){
                            tempSum+=grid[i-1][j-1+x];
                        }
                        if(tempSum!=60) extrachecker = false;
                        if(extrachecker) magicGrid++;
                    }
                }
            }
        }
        return magicGrid;
    }
};