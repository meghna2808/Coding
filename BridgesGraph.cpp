class Solution {
public:
    int timer=0;
   void dfs(int source, int parent,vector<int>&time , vector<int>&low,vector<vector<int>>&adj_list, vector<vector<int>>&bridges,vector<bool>&visited)
   {
    visited[source]=true;
    timer++;
    time[source]=low[source]=timer;
    for(int neigh: adj_list[source])
    {
        if(neigh==parent)continue;
        if(visited[neigh]==false)
        {
            dfs(neigh,source,time,low,adj_list,bridges,visited);
            low[source]=min(low[source],low[neigh]);
            if(low[neigh]>time[source])
            {
                bridges.push_back({neigh,source});
            }
        }
        else
        {
            low[source]=min(low[neigh],low[source]);
        }
        
    }
   }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj_list(n);
        vector<vector<int>>bridges;
        for(int i=0;i<connections.size();i++)
        {
            // cout<<connections[i][0]<<" "<<connections[i][1]<<endl;
            adj_list[connections[i][0]].push_back(connections[i][1]);
            adj_list[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int>time(n);
        vector<int>low(n);
        vector<bool>visited(n,false);
        dfs(0,-1,time , low ,adj_list,bridges,visited);
        return bridges;
       
        
    }
};