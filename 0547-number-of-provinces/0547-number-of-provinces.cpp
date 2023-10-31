class Solution {
public:

    void BFSRec(vector<vector<int>> & isConnected,int i,bool visited[]){
        int V = isConnected.size();
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int temp = q.front();
            visited[temp]=true;
            q.pop(); 
            for(int j=0;j<V;j++){
                if(isConnected[temp][j]){
                    if(visited[j]==false){
                        q.push(j);
                    }
                }
            }
        }
    }

    int BFS(vector<vector<int>> & isConnected){
        int V = isConnected.size();
        bool visited[V];
        memset(visited,0,sizeof(visited));
        int count=0;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                count++;
                BFSRec(isConnected,i,visited);
            }
        }
        return count;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        return BFS(isConnected);
    }
};