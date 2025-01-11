class DSU
{
    public:
    vector<int>parent,rank;
    DSU(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findPar(int node)
    {
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node]);
    }
    void setUnion(int u, int v)
    {
        u=findPar(u);
        v=findPar(v);
        if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else if(rank[v]>rank[u])
        {
            parent[u]=v;
        }
        else
        {
            parent[u]=v;
            rank[v]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            // cout<<dsu.findPar(edges[i][0])<<" "<<dsu.findPar(edges[i][1])<<endl;
            if(dsu.findPar(edges[i][0])==dsu.findPar(edges[i][1]))
            {
                x=edges[i][0];
                y=edges[i][1];
            }
            else
            {
                dsu.setUnion(edges[i][0],edges[i][1]);
                // cout<<dsu.findPar(edges[i][0])<<" "<<dsu.findPar(edges[i][1])<<endl;
            }
            // cout<<"end"<<endl;
        }
        return {x,y};
    }
};