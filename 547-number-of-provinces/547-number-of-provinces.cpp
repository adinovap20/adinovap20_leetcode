class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n+1);
        vector<bool> visited(n+1,false);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1){
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }
        }
        function<void(int)> DFS = [&](int s){
            visited[s] = true;
            for(auto x : graph[s]){
                if(!visited[x]){
                    DFS(x);
                }
            }
        };
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                DFS(i);
                cnt++;
            }
        }
        return cnt;
    }
};