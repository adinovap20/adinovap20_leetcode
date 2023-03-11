//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> DP(N, vector<int>(N));
        for(int i=0; i<N; i++) DP[0][i] = Matrix[0][i];
        for(int i=1; i<N; i++){
            for(int j=0; j<N; j++){
                DP[i][j] = DP[i-1][j] + Matrix[i][j];
                if(j-1 >= 0) DP[i][j] = max(DP[i][j], DP[i-1][j-1] + Matrix[i][j]);
                if(j+1 < N) DP[i][j] = max(DP[i][j], DP[i-1][j+1] + Matrix[i][j]);
            }
        }
        return *max_element(DP[N-1].begin(), DP[N-1].end());
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends