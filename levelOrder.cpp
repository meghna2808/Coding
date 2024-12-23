vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>>level;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>v;
            for(int i=0;i<n;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }

            }
            level.push_back(v);

        }
        return level;
}
// time :O(n) n: no of nodes
//space : O(n)    