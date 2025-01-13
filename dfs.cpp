void dfs(vector<set<int>>&adj_list,int source, vector<bool>&visited,vector<int>&temp)
{
    if(visited[source]==true) return;
    visited[source]=true;
    temp.push_back(source);
    for(int neigh:adj_list[source])
    {
        dfs(adj_list,neigh,visited,temp);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<set<int>>adj_list(V);
    vector<bool>visited(V,false);
    for(int i=0;i<E;i++)
    {
        adj_list[edges[i][0]].insert(edges[i][1]);
        adj_list[edges[i][1]].insert(edges[i][0]);
    }
    vector<vector<int>>df;
    for(int i=0;i<V;i++)
    {
        vector<int>temp;
        if(visited[i]==false)
        {

            dfs(adj_list,i,visited,temp);
            df.push_back(temp);
        }
        

    }
    return df;
}