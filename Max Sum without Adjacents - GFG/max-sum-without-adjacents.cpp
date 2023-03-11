//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    if(n==1) return arr[0];
	    vector<int> DP(n); DP[0] = arr[0]; DP[1] = arr[1];
	    vector<int> mx(n); mx[0] = DP[0]; mx[1] = max(DP[0], DP[1]);
	    for(int i=2; i<n; i++){
	        DP[i] = arr[i] + mx[i-2];
	        mx[i] = max(mx[i-1], DP[i]);
	    }
	    return max(DP[n-1], DP[n-2]);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends