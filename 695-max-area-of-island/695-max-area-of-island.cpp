class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        function<bool(int,int)> isValid = [&](int a, int b){
            if(a<0 || b<0 || a>=n || b>=m) return false;
            return true;
        };
        int ans = 0; int cnt = 0;
        function<void(int,int)> DFS = [&](int x, int y){
            visited[x][y] = true; cnt++;
            if(isValid(x,y+1) && !visited[x][y+1] && grid[x][y+1]==1) DFS(x,y+1);
            if(isValid(x,y-1) && !visited[x][y-1] && grid[x][y-1]==1) DFS(x,y-1);
            if(isValid(x+1,y) && !visited[x+1][y] && grid[x+1][y]==1) DFS(x+1,y);
            if(isValid(x-1,y) && !visited[x-1][y] && grid[x-1][y]==1) DFS(x-1,y);
        };
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]==1){
                    cnt = 0;
                    DFS(i,j);
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};