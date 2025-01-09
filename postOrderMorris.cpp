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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        while(root!=NULL)
        {
            if(root->right==NULL)
            {
                postorder.push_back(root->val);
                root=root->left;
            }
            else
            {
                TreeNode* temp=root->right;
                while(temp->left!=NULL && temp->left!=root)
                {
                    temp=temp->left;
                }
                if(temp->left==NULL)
                {
                    postorder.push_back(root->val);
                    temp->left=root;
                    root=root->right;
                }
                else
                {
                    temp->left=NULL;
                    root=root->left;
                }
            }

        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
        
    }
};