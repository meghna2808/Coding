class Solution {
public:
    vector<int>result;
    vector<int>subnodes;
    void dfs(int node,int parent,vector<vector<int>>&adj_list)
     {
        for(int child:adj_list[node])
        {
            if(child!=parent)
            {
                dfs(child,node,adj_list);
                subnodes[node]+=subnodes[child];
                result[node]+=result[child]+subnodes[child];
            }
        }
     }
     void dfs2(int node, int parent, vector<vector<int>>&adj_list)
     {
        for(int child:adj_list[node])
        {
            if(child!=parent)
            {
                result[child]=result[node]-subnodes[child]+(result.size()-subnodes[child]);
                dfs2(child,node,adj_list);
            }
        }
     }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj_list(n);
        for(int i=0;i<edges.size();i++)
        {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);

        }
        result.resize(n,0);
        subnodes.resize(n,1);
        dfs(0,-1,adj_list);
        for(int i=0;i<n;i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
         for(int i=0;i<n;i++)
        {
            cout<<subnodes[i]<<" ";
        }
        cout<<endl;
        dfs2(0,-1,adj_list);
        return result;

        
    }
};