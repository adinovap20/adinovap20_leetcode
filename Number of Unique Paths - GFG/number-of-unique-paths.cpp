//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int n, int m)
    {
        vector<vector<int>> DP(n, vector<int>(m));
        for(int i=0; i<n; i++) DP[i][0] = 1;
        for(int i=0; i<m; i++) DP[0][i] = 1;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                DP[i][j] = DP[i-1][j] + DP[i][j-1];
            }
        }
        return DP[n-1][m-1];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends