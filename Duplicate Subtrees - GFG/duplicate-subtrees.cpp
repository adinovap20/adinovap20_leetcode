//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = "";
        currVal+=ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void preorder(Node* root,vector<int> &temp){
    if(!root){
        return ;
    }
    //cout<<root->data<<" ";
    temp.push_back(root->data);
    preorder(root->left,temp);
    preorder(root->right,temp);
}


// } Driver Code Ends
//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree
vector<Node*> printAllDups(Node* root)
{
    function<bool(Node*, Node*)> isEqual = [&](Node* a, Node* b){
        if(a==NULL && b==NULL) return true;
        if(a==NULL && b!=NULL) return false;
        if(b==NULL && a!=NULL) return false;
        if(a->data != b->data) return false;
        bool t1 = isEqual(a->left, b->left);
        bool t2 = isEqual(a->right, b->right);
        return (t1 && t2);
    };
    vector<Node*> arr;
    function<void(Node*)> inorder = [&](Node* s){
        if(s==NULL) return;
        inorder(s->left);
        arr.push_back(s);
        inorder(s->right);
    };
    inorder(root);
    vector<Node*> ans;
    for(int i=0; i<arr.size()-1; i++){
        for(int j=i+1; j<arr.size(); j++){
            if(isEqual(arr[i],arr[j])){
                bool flag = false;
                for(int k=0; k<ans.size(); k++){
                    if(isEqual(ans[k],arr[i])){
                        flag = true; break;
                    }
                }
                if(flag == false){
                    ans.push_back(arr[i]);
                }
            }
        }
    }
    // for(auto x : st){
    //     ans.push_back(x);
    // }
    return ans;
}

//{ Driver Code Starts.








int main() {


    int tc;
    cin>>tc;
    while(tc--)
    {
        
        string treeString;
        getline(cin>>ws,treeString);
        //cin.ignore();
        //cin.clear();
        //cout<<treeString<<"\n";

        Node* root = buildTree(treeString);
        vector<Node*> res = printAllDups(root);

        vector<vector<int>>ans;
        
        for(int i=0;i<res.size();i++){
            vector<int> temp;
            preorder(res[i],temp);
            ans.push_back(temp);
        }
        
        sort(ans.begin(),ans.end());
        
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
        //cout<<"\n";

        
    }
return 0;
}





// } Driver Code Ends