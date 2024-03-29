//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
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
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends