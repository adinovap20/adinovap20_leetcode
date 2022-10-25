//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n){
        int zc = 0; int oc = 0; int tc = 0;
        for(int i=0; i<n; i++){
            if(a[i]==0) zc++;
            if(a[i]==1) oc++;
            if(a[i]==2) tc++;
        }
        for(int i=0; i<n; i++){
            if(zc!=0){
                a[i] = 0; zc--; continue;
            }
            if(oc!=0){
                a[i] = 1; oc--; continue;
            }
            if(tc!=0){
                a[i] = 2; tc--; continue;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends