//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int lptr = 0; int rptr = 0;
        int cnt = 0;
        vector<int> pos;
        for(int i=0; i<n; i++){
            if(arr[i]=='O') pos.push_back(i);
        }
        int ptr = 0; int ans = 0;
        while(lptr < n && rptr < n){
            if(cnt == m){
                if(arr[rptr]=='A'){
                    ans = max(ans, rptr-lptr+1);
                    rptr++;
                    continue;
                }
                lptr = pos[ptr++]; lptr++; 
                if(lptr >= n) continue;
                ans = max(ans, rptr-lptr+1); rptr++; continue;
            }
            if(arr[rptr]=='O') cnt++;
            ans = max(ans, rptr-lptr+1);
            rptr++;
            continue;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends