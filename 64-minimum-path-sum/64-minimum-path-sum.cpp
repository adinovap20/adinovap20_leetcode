class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> DP(n, vector<int>(m));
        DP[0][0] = grid[0][0];
        for(int j=1; j<m; j++) DP[0][j] = DP[0][j-1] + grid[0][j];
        for(int i=1; i<n; i++) DP[i][0] = DP[i-1][0] + grid[i][0];
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + grid[i][j];
            }
        }
        return DP[n-1][m-1];
    }
};