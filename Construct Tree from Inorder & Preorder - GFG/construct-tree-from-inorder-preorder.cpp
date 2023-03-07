//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        function<Node*(vector<int>&,vector<int>&)> DFS = [&](vector<int>& inorder, vector<int>& preorder){
            if(preorder.size()==1){
                Node* tmp = new Node(preorder[0]);
                return tmp;
            }
            if(preorder.size()==0){
                Node* tmp = NULL;
                return tmp;
            }
            vector<int> lft_in;
            int pos = 0;
            for(int i=0; i<inorder.size(); i++){
                if(inorder[i]==preorder[0]){
                    pos = i; break;
                }
                lft_in.push_back(inorder[i]);
            }
            vector<int> rgt_in;
            for(int i=pos+1; i<inorder.size(); i++){
                rgt_in.push_back(inorder[i]);
            }
            vector<int> lft_pre;
            vector<int> rgt_pre;
            for(int i=1; i<=lft_in.size(); i++){
                lft_pre.push_back(preorder[i]);
            }
            for(int i=lft_in.size()+1; i<preorder.size(); i++){
                rgt_pre.push_back(preorder[i]);
            }
            Node* tmp = new Node(preorder[0]);
            tmp->left = DFS(lft_in, lft_pre);
            tmp->right = DFS(rgt_in, rgt_pre);
            return tmp;
        };
        vector<int> inorder;
        vector<int> preorder;
        for(int i=0; i<n; i++) inorder.push_back(in[i]);
        for(int i=0; i<n; i++) preorder.push_back(pre[i]);
        Node* tmp = DFS(inorder, preorder);
        return tmp;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends