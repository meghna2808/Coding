#include<bits/stdc++.h>
vector<int> bottomView(TreeNode<int> * root){
    queue<pair<TreeNode<int> *,int>>q;
    if(root==NULL) return {};
    q.push({root, 0});
    map<int,int>m;
    // m[0]=root->val;
    
    int count=0;
    while(!q.empty())
    {
        count++;
        TreeNode<int>* front=q.front().first;
        int index=q.front().second;
        m[index]=front->data;
        q.pop();
        if(front->left)
        {
          q.push({front->left, index - 1});
        }
        if(front->right)
        {
          q.push({front->right, index + 1});
        }

    }
    vector<int>bottom_view;
    for(auto i :m)
    {
        bottom_view.push_back(i.second);
    }
    return bottom_view;
    
}
