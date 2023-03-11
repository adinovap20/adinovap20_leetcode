//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        vector<int> DP(N+2);
        DP[0] = 0; DP[1] = cost[0];
        for(int i=1; i<N; i++){
            DP[i+1] = min(DP[i], DP[i-1]) + cost[i];
        }
        DP[N+1] = min(DP[N-1], DP[N]);
        return DP[N+1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends