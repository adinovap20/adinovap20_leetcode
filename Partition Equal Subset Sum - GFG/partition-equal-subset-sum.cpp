//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        if(sum%2==1) return 0;
        sum = sum/2;
        bool flag = false;
        vector<vector<int>> DP(N, vector<int>(sum+1,-1));
        function<int(int,int)> rec = [&](int pos, int cur){
            if(cur > sum) return 0;
            if(cur == sum){
                flag = true;
                return 1;
            }
            if(pos >= N) return 0;
            if(DP[pos][cur] != -1) return DP[pos][cur];
            int a = rec(pos+1, cur+arr[pos]);
            int b = rec(pos+1, cur);
            if(a || b) return DP[pos][cur] = 1;
            return DP[pos][cur] = 0;
        };
        rec(0,0);
        return flag;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends