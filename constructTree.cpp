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
    TreeNode* constructTree(vector<int>&nums,int start, int end)
    {
        if(start>end) return NULL;
        int max_index=start,max_value=INT_MIN;
        for(int i=start;i<=end;i++)
        {
            if(nums[i]>max_value)
            {
                max_index=i;
                max_value=nums[i];
            }
        }
        TreeNode* root=new TreeNode(max_value);
        root->left=constructTree(nums,start,max_index-1);
        root->right=constructTree(nums,max_index+1,end);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return constructTree(nums,0,n-1);
        
    }
};