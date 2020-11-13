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
class Solution {
public:
    void ps(TreeNode* root, int sum, unordered_map<int, int> &path, int &ans, int k){
        if(!root)
            return ;
        
        
        if(k + root->val == sum )
            ans++;
       
        ans += path[ k + root->val - sum];
        
        path[root->val + k]++;
        ps(root->right, sum, path, ans, k+root->val);
        ps(root->left, sum, path, ans, k+root->val);
        path[root->val + k]--;   
        
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> path;
        
        int ans = 0;
        ps(root, sum, path, ans, 0);
        return ans;
    }
};
