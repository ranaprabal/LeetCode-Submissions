class Solution {
public:

    void dfs(pair<int,int>node,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        vis[node.first][node.second]=1;
        int dx[4] = {0,1,-1,0};
        int dy[4] = {1,0,0,-1};
        for(int i=0;i<4;i++){
            int x = node.first + dx[i];
            int y = node.second + dy[i];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size()){
                if(vis[x][y]==0 && grid[x][y]==0){
                    dfs({x,y},grid,vis);
                }
            }
        }
    }


    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>g(n*3,vector<int>(3*m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='/'){
                    g[3*i][3*j] = 0;
                    g[3*i+1][3*j] = 0;
                    g[3*i][3*j+1] = 0;
                    g[3*i+2][3*j+2] = 0;
                    g[3*i+1][3*j+2] = 0;
                    g[3*i+2][3*j+1] = 0;
                    g[3*i+1][3*j+1] = 1;
                    g[3*i][3*j+2] = 1;
                    g[3*i+2][3*j] = 1;
                }
                if(grid[i][j]=='\\'){
                    g[3*i][3*j] = 1;
                    g[3*i+1][3*j] = 0;
                    g[3*i][3*j+1] = 0;
                    g[3*i+2][3*j+2] = 1;
                    g[3*i+1][3*j+2] = 0;
                    g[3*i+2][3*j+1] = 0;
                    g[3*i+1][3*j+1] = 1;
                    g[3*i][3*j+2] = 0;
                    g[3*i+2][3*j] = 0;
                }
                if(grid[i][j]==' '){
                    g[3*i][3*j] = 0;
                    g[3*i+1][3*j] = 0;
                    g[3*i][3*j+1] = 0;
                    g[3*i+2][3*j+2] = 0;
                    g[3*i+1][3*j+2] = 0;
                    g[3*i+2][3*j+1] = 0;
                    g[3*i+1][3*j+1] = 0;
                    g[3*i][3*j+2] = 0;
                    g[3*i+2][3*j] = 0;
                }
            }
        }

        vector<vector<bool>>vis(3*n,vector<bool>(3*m,0));

        int cnt =0;
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*m;j++){
                if(g[i][j]==0 && vis[i][j]==0){
                    cout<<i<<" "<<j;
                    cnt++;
                    dfs({i,j},g,vis);
                }
            }
        }
        return cnt;
    }
};