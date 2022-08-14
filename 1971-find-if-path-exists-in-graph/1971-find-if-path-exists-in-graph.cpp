class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    
    void DFS(int s){
        visited[s] = true;
        for(auto x : graph[s]){
            if(!visited[x]){
                DFS(x);
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        graph.resize(n+1);
        visited.resize(n+1,false);
        for(auto x : edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        DFS(source);
        return visited[destination];
    }
};