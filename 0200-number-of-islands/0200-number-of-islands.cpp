class Solution {
public:
    int numIslands(vector<vector<char>>& arr) {
        int n = arr.size(); int m = arr[0].size(); int cnt = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        function<bool(int,int)> isValid = [&](int a, int b){
            if(a<0 || b<0 || a>=n || b>=m) return false;
            return true;
        };
        function<void(int,int)> DFS = [&](int x, int y){
            visited[x][y] = true;
            if(isValid(x,y+1) && !visited[x][y+1] && arr[x][y+1]=='1') DFS(x,y+1);
            if(isValid(x,y-1) && !visited[x][y-1] && arr[x][y-1]=='1') DFS(x,y-1);
            if(isValid(x+1,y) && !visited[x+1][y] && arr[x+1][y]=='1') DFS(x+1,y);
            if(isValid(x-1,y) && !visited[x-1][y] && arr[x-1][y]=='1') DFS(x-1,y);
        };
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]=='0'){
                    visited[i][j] = true; continue;
                }
                if(!visited[i][j]){
                    cnt++;
                    DFS(i,j);
                }
            }
        }
        return cnt;
    }
};