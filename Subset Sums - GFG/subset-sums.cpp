//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> ans;
        function<void(int, int, vector<int>)> DFS = [&](int ptr, int sum, vector<int> res){
            if(ptr==N) ans.push_back(sum);
            if(ptr>=N) return;
            // Take
            res.push_back(arr[ptr]);
            DFS(ptr+1, sum+arr[ptr], res);
            // Don't Take
            res.pop_back();
            DFS(ptr+1, sum, res);
        };
        DFS(0,0,{});
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends