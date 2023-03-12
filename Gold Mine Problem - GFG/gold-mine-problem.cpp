//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> grid)
    {
        vector<vector<int>> DP(n, vector<int>(m));
        for(int i=0; i<n; i++){
            DP[i][0] = grid[i][0];
        }
        for(int j=1; j<m; j++){
            for(int i=0; i<n; i++){
                int a = (i-1>=0 && i-1<n) ? DP[i-1][j-1] : (int)-1e8;
                int b = (i>=0 && i<n) ? DP[i][j-1] : (int)-1e8;
                int c = (i+1>=0 && i+1<n) ? DP[i+1][j-1] : (int)-1e8;
                DP[i][j] = grid[i][j]+max({a,b,c});
            }
        }
        int mx = 0;
        for(int i=0; i<n; i++){
            mx = max(mx, DP[i][m-1]);
        }
        return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends