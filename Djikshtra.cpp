class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n=adj.size();
        vector<int>shortestDist(n,INT_MAX);
        shortestDist[src]=0;
        set<pair<int,int>>s;
        s.insert({0,src});
        while(!s.empty())
        {
            auto itt = *(s.begin()); 
            int node = itt.second; 
            int dist = itt.first;
            s.erase(itt);
            
            for(auto it: adj[node])
            {
                if(dist+it.second<shortestDist[it.first])
                {
                    if(shortestDist[it.first]!=INT_MAX)
                    {
                        s.erase({shortestDist[it.first],it.first});
                    }
                    shortestDist[it.first]=dist+it.second;
                    s.insert({dist+it.second,it.first});
                }
            }
        }
        return shortestDist;
        
        // Code here
    }
};