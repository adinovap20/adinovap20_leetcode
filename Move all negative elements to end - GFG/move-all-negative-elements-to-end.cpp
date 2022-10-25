//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> tmp; vector<int> tmp2;
        for(int i=0; i<n; i++){
            if(arr[i]>=0){
                tmp.push_back(arr[i]);
            }else{
                tmp2.push_back(arr[i]);
            }
        }
        for(int i=0; i<tmp.size(); i++){
            arr[i] = tmp[i];
        }
        for(int i=tmp.size(); i<n; i++){
            arr[i] = tmp2[i-tmp.size()];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends