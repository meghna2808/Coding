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
    void inorder_traversal(TreeNode* root , vector<int>&inorder)
    {
        if(root==NULL) return ;
        inorder_traversal(root->left,inorder);
        inorder.push_back(root->val);
        inorder_traversal(root->right,inorder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        inorder_traversal(root,inorder);
        return inorder;
        
    }
};
//using stack
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode* >s;
        s.push(root);
        vector<int>inorder;
        while(!s.empty())
        {
            TreeNode* top=s.top();
            if(top->left==NULL)
            {
                inorder.push_back(top->val);
                s.pop();
                if(top->right)
                {
                    s.push(top->right);
                    top->right=NULL;
                }
            }
            else
            {
                s.push(top->left);
                top->left=NULL;
            }

        }
        return inorder;
        
    }
};
//using morris