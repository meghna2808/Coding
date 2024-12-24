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


//using recursion
void right_view(TreeNode* root, map<int,int>&view,int level)
    {
        if(root==NULL) return ;
        if(view.find(level)==view.end())
        {
            view[level]=root->val;
        }
        right_view(root->right,view,level+1);
        right_view(root->left,view,level+1);
        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>view;
        right_view(root,view,1);
        vector<int>right_view;
        for(auto i: view)
        {
            right_view.push_back(i.second);
        }
        return right_view;
        
    }
