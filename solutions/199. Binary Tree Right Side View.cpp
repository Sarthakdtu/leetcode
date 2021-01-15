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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_view;
        if(!root)
            return right_view;
        queue<TreeNode*> q;
        int level = 0;
        
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                if(size == 0 )
                    right_view.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            level++;
        }
        return right_view;
    }
};
