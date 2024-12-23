class Solution {
public:
    int max_sum=INT_MIN;
    int maxPath(TreeNode*root)
    {
        if(root==NULL) return 0;
        int left_sum=max(maxPath(root->left),0);
        int right_sum=max(maxPath(root->right),0);
        int sum=root->val+left_sum+right_sum;
        max_sum=max(max_sum,sum);
        return root->val+max(left_sum,right_sum);

    }
    int maxPathSum(TreeNode* root) {
        int sum=maxPath(root);
        return max_sum;
        
    }
};
//time :O(n)
//space:O(n)