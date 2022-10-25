class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); int m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int org_color = image[sr][sc];
        function<void(int,int)> DFS = [&](int x, int y){
        	// cout << x << " " << y << endl;
            if(x<0 || x>=n || y<0 || y>=m) return;
            if(image[x][y]!=org_color) return;
            if(visited[x][y]) return;
            image[x][y] = color;
            visited[x][y] = true;
            DFS(x+1, y);
            DFS(x-1,y);
            DFS(x,y+1);
            DFS(x,y-1);
        };
        DFS(sr,sc);
        return image;
    }
};
