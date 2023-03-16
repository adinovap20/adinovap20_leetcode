//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int target)
	{
	    vector<int> tmp;
	    for(int i=0; i<n; i++){
	        if(arr[i]!=0) tmp.push_back(arr[i]);
	    }
	    int M = 1e9+7;
	    int z = n - tmp.size();
	    int pw = 1;
	    for(int i=0; i<z; i++){
	        pw = (pw%M * 2%M)%M;
	    }
	    int SUM = 0;
	    for(auto x : tmp) SUM+=x;
	    if(SUM < target) return 0;
	    vector<vector<int>> DP(n, vector<int>(SUM+1,-1));
	    function<int(int,int)> rec = [&](int pos, int sum){
	        if(sum==0) return 1;
	        if(pos == 0){
	            return (int)(tmp[0]==sum);
	        }
	        if(DP[pos][sum]!=-1) return DP[pos][sum];
	        int a = rec(pos-1, sum);
	        int b = 0;
	        if(tmp[pos]<=sum) b = rec(pos-1, sum-tmp[pos]);
	        return DP[pos][sum]=(a%M+b%M)%M;
	    };
	    return pw*rec(tmp.size()-1, target);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends