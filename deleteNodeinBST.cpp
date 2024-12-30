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
    TreeNode* deleteN(TreeNode* root , int key)
    {
        if(root==NULL) return NULL;
        if(root->val>key)
        {
            root->left=deleteN(root->left,key);

        }
        else if(root->val<key)
        {
            root->right=deleteN(root->right,key);
        }
        else
        {
            if(root->left==NULL && root->right==NULL) return NULL;
            else if(root->left==NULL || root->right==NULL)
            {
                return root->left? root->left: root->right;
            }
            else
            {
                TreeNode* temp=root->right;
                while(temp->left!=NULL)
                {
                    temp=temp->left;
                }
                root->val=temp->val;
                root->right=deleteN(root->right,temp->val);
            }
        }
        return root;

        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteN(root,key);
        
        
    }
};