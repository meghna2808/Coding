class Solution {
public:
    int check_height(TreeNode* root, bool &balanced)
    {
        if(root==NULL) return 0;

        int left_height=check_height(root->left,balanced);
        int right_height=check_height(root->right, balanced);
        if(abs(left_height-right_height)>1) balanced = false;
        return 1+ max(left_height,right_height);
    }
    bool isBalanced(TreeNode* root) {
        bool balanced=true;
        check_height(root,balanced);
        return balanced;

        
    }
};