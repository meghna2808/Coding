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

    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*front=q.front();
            q.pop(); // removing the top element
            TreeNode*left=front->left;
            front->left=front->right;
            front->right=left;
            if(front->right) q.push(front->right);
            if(front->left)q.push(front->left);
            
        }
        return root;
        
    }
};
//time : o(n)
//space :O(n)