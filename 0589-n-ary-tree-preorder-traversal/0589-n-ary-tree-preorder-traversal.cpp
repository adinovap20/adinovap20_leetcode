/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        function<void(Node*)> go = [&](Node* s){
            if(s==NULL) return;
            ret.push_back(s->val);
            for(auto x : s->children){
                go(x);
            }
        };
        go(root);
        return ret;
    }
};