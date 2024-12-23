class Solution {
public:
    void inorder_sort(TreeNode* root, vector<int>&inorder)
    {
        if(root==NULL) return ;
        inorder_sort(root->left,inorder);
        inorder.push_back(root->val);
        inorder_sort(root->right,inorder);
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        inorder_sort(root,inorder);
        return inorder[k-1];
        
    }
};