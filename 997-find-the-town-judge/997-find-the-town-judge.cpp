class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph1(n+1);
        vector<vector<int>> graph2(n+1);
        for(auto x : trust){
            graph1[x[1]].push_back(x[0]);
            graph2[x[0]].push_back(x[1]);
        }
        for(int i=1; i<=n; i++){
            if(graph1[i].size()==n-1 && graph2[i].size()==0){
                return i;
            }
        }
        return -1;
    }
};