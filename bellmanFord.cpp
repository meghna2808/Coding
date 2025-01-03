vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
        vector<int>shortestDist(v,1e8);
        shortestDist[src]=0;
        for(int i=0;i<v-1;i++)
        {
            for(auto edge:edges)
            {
                int u=edge[0];
                int v=edge[1];
                int dist=edge[2];
                if(shortestDist[u]!=1e8&& shortestDist[u]+dist<shortestDist[v])
                {
                    // cout<< shortestDist[v]<<" "<<shortestDist[u]+dist<<endl;
                    // if(i==v-1) return {-1};
                    shortestDist[v]=shortestDist[u]+dist;
                }
                
            }
        }
        for(auto edge:edges)
            {
                int u=edge[0];
                int v=edge[1];
                int dist=edge[2];
                if(shortestDist[u]!=1e8 && shortestDist[u]+dist<shortestDist[v])
                {
                    return {-1};
                }
                
            }
        return shortestDist;
        // Code here
    }