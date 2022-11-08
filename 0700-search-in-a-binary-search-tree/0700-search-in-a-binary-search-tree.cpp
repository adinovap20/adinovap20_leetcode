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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ret = NULL;
        function<void(TreeNode*)> go = [&](TreeNode* s){
            if(s==NULL) return;
            if(s->val == val){
                ret = s; return;
            }
            if(s->val < val){
                go(s->right);
            }
            go(s->left);
        };
        go(root);
        return ret;
    }
};