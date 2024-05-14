class Solution {
public:

    int DFS(pair<int,int>cur,vector<vector<int>>&grid){
        int i = cur.first;
        int j = cur.second;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int temp = 0;
        int curr = grid[i][j];
        grid[i][j] =0;
        for(int p=0;p<4;p++){
            int x = i + dx[p];
            int y = j + dy[p];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size()){
                if(grid[x][y]){
                    temp = max(temp,DFS({x,y},grid));
                }
            }
        }
        grid[i][j] = curr;
        return temp + curr;
    }


    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    ans  = max(ans,DFS({i,j},grid));
                }
            }
        }
        return ans;
    }
};