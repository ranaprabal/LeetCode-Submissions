class Solution {
public:
    int BFS(vector<vector<int>>&dist){
        int n = dist.size();
        int m = dist[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        deque<pair<int,pair<int,int>>>q;
        int minn = dist[0][0];
        q.push_front({minn,{0,0}});
        visited[0][0]=1;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        while(q.size()){
            auto temp = q.front();
            q.pop_front();
            auto distance = temp.first;
            auto node = temp.second;
            if(node.first==n-1 && node.second==m-1) return distance;
            for(int i=0;i<4;i++){
                int x = dx[i] + node.first;
                int y = dy[i] + node.second;
                if(x>=0 && y>=0 && x<n && y<m){
                    if(dist[x][y]==0 || visited[x][y]==1) continue;
                    visited[x][y] = 1;
                    if(dist[x][y]>=distance){
                        q.push_front({min(distance,dist[x][y]),{x,y}});
                    }
                    else 
                        q.push_back({min(distance,dist[x][y]),{x,y}});
                }
            }
        }
        return 1e9;
    }
    void thiefBFS(vector<vector<int>>&grid,vector<vector<int>>&dist){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                    dist[i][j] =0;
                }
            }
        }
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        while(q.size()){
            auto temp = q.front();
            q.pop();
            int distance = temp.first;
            pair<int,int>node = temp.second;
            for(int i=0;i<4;i++){
                int x = dx[i] + node.first;
                int y = dy[i] + node.second;
                if(x>=0 && y>=0 && x<n && y<m){
                    if(dist[x][y]>distance + 1){
                        q.push({distance+1,{x,y}});
                        dist[x][y] = 1+distance;
                    }
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        thiefBFS(grid,dist);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans = BFS(dist);
        if(ans==1e9) return 0;
        return ans;
    }
};