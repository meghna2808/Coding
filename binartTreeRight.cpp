class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL) return {};
        vector<int>view;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* front =q.front();
                q.pop();
                if(i==n-1)
                {
                    view.push_back(front->val);
                }
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }

        }
        return view;
        
    }
};