//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long bestNode(int n, vector<int> &arr, vector<int> &parent) {
        vector<vector<int>> graph(n+1);
        for(int i=1; i<n; i++){
            graph[i+1].push_back(parent[i]);
            graph[parent[i]].push_back(i+1);
        }
        vector<long long> pos(n+1, -1E18);
        vector<long long> neg(n+1, -1E18);
        vector<bool> visited(n+1, false);
        function<void(long long)> DFS = [&](long long s){
            visited[s] = true;
            if(graph[s].size()==1 && s!=1){
                pos[s] = arr[s-1];
                neg[s] = -arr[s-1];
                return;
            }
            for(auto x : graph[s]){
                if(!visited[x]){
                    DFS(x);
                }
            }
            for(auto x : graph[s]){
                if(x==parent[s-1]) continue;
                pos[s] = max(pos[s], arr[s-1]+neg[x]);
                neg[s] = max(neg[s], -arr[s-1]+pos[x]);
            }
        };
        DFS(1);
        long long ans = -1E18;
        for(int i=1; i<=n; i++){
            ans = max(ans, pos[i]);
        }
        if(n==1){
            return arr[0];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends