//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findHeight(int N, int arr[]){
        vector<vector<int>> graph(N);
        int root;
        for(int i=0; i<N; i++){
            if(arr[i]==-1){
                root = i; continue;
            }
            graph[arr[i]].push_back(i);
            graph[i].push_back(arr[i]);
        }
        int ans = 0;
        function<void(int,int)> DFS = [&](int s,int level){
            ans = max(ans, level);
            for(auto x : graph[s]){
                if(x == arr[s]) continue;
                DFS(x, level+1);
            }
        };
        DFS(root, 1);
        return ans;
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
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends