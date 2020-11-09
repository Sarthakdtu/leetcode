/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct res{
  int a;
    int b;
};
class Solution {
public:
    
    res dia(TreeNode* root){
        if(!root)
            return {0, 0};
        res l = dia(root->left);
        res r = dia(root->right);
        int lo = max(max(l.b, r.b), l.a + r.a + 1);
        res ans;
        ans.a = max(l.a, r.a) + 1;
        ans.b = lo;
        return ans;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
         res ans = dia(root);
        ans.b = max(0, ans.b-1);
            return ans.b;
    }
};
