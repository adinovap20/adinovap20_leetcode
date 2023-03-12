//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<int>> DP(n, vector<int>(target+1, -1));
        bool flag = false;
        function<bool(int,int)> rec = [&](int pos, int sum){
            if(sum > target) return false;
            if(sum == target){
                flag = true;
                return true;
            }
            if(pos >= n) return false;
            if(DP[pos][sum]==0) return false;
            if(DP[pos][sum]==1) return true;
            bool a = rec(pos+1, sum+arr[pos]);
            bool b = rec(pos+1, sum);
            if(a == true || b==true){
                DP[pos][sum] = 1;
            }else{
                DP[pos][sum] = 0;
            }
            return (a||b);
        };
        rec(0,0);
        return flag;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends