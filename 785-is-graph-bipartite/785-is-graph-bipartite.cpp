class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<int> color(n,0);
        function<void(int)> DFS = [&](int s){
            visited[s] = true;
            for(auto x : graph[s]){
                if(!visited[x]){
                    color[x] = 1 - color[s];
                    DFS(x);
                }
            }
        };
        for(int i=0; i<n; i++){
            if(!visited[i]){
                DFS(i);
            }
        }
        for(int i=0; i<n; i++){
            for(auto x : graph[i]){
                if(color[x]==color[i]){
                    return false;
                }
            }
        }
        return true;
    }
};