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
    void ps(TreeNode* root, int sum, vector<int> &path, int &ans){
        if(!root)
            return ;
        
        path.push_back(root->val);
        
        int s = 0;
        for(int i=path.size()-1;i>-1;i--){
            s += path[i];
            if(s == sum){
                ans++;
            }
        }
        ps(root->right, sum, path, ans);
        ps(root->left, sum, path, ans);
        path.pop_back();
        
        
        
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        vector<int> path;
        
        int ans = 0;
        ps(root, sum, path, ans);
        return ans;
    }
};
