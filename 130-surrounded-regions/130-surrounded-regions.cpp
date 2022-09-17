class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(); int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        function<bool(int,int)> isValid = [&](int a,int b){
            if(a<0 || b<0 || a>=n || b>=m) return false;
            return true;
        };
        function<void(int,int)> DFS = [&](int x, int y){
            visited[x][y] = true;
            if(isValid(x,y+1) && !visited[x][y+1] && board[x][y+1]=='O') DFS(x,y+1);
            if(isValid(x,y-1) && !visited[x][y-1] && board[x][y-1]=='O') DFS(x,y-1);
            if(isValid(x+1,y) && !visited[x+1][y] && board[x+1][y]=='O') DFS(x+1,y);
            if(isValid(x-1,y) && !visited[x-1][y] && board[x-1][y]=='O') DFS(x-1,y);
        };
        for(int i=0; i<n; i++){
            if(!visited[i][0] && board[i][0]=='O'){
                DFS(i,0);
            }
            if(!visited[i][m-1] && board[i][m-1]=='O'){
                DFS(i,m-1);
            }
        }
        for(int i=0; i<m; i++){
            if(!visited[0][i] && board[0][i]=='O'){
                DFS(0,i);
            }
            if(!visited[n-1][i] && board[n-1][i]=='O'){
                DFS(n-1,i);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};