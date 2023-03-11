//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> DP(n, vector<int>(m));
        int M = 1E9 + 7; bool flag = false;
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0){
                flag = true; DP[i][0] = 0; continue;
            }
            if(grid[i][0] == 1 && flag==false){
                DP[i][0] = 1; continue;
            }
            DP[i][0] = 0;
        }
        flag = false;
        for(int i=0; i<m; i++){
            if(grid[0][i] == 0){
                flag = true; DP[0][i] = 0; continue;
            }
            if(grid[0][i] == 1 && flag==false){
                DP[0][i] = 1; continue;
            }
            DP[0][i] = 0;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                DP[i][j] = (grid[i][j]==1) ? ((DP[i-1][j]%M+DP[i][j-1]%M)%M) : 0;
            }
        }
        return DP[n-1][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends