//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    double findArea(int A,int B,int C){
        double s = (A+B+C)/2.0;
        double arSq = s*(s-A)*(s-B)*(s-C);
        if(arSq <= 0) return 0.0;
        return (double)sqrt(arSq);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<fixed<<setprecision(3);
        cout<<ob.findArea(A,B,C)<<"\n";
    }
}
// } Driver Code Ends