/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> go = [&](TreeNode* s){
            if(s==NULL) return 0;
            int a = go(s->left);
            int b = go(s->right);
            return max(a+1, b+1);
        };
        ans = go(root);
        return ans;
    }
};