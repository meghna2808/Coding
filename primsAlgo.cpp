priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            pq;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<<pair<int,int>> >pq;
        pq.push({0,0});
        int result=0;
        vector<bool>visited(V,false);
        while(!pq.empty())
        {
            int source=pq.top().second;
            int weight=pq.top().first;
            pq.pop();
            if(visited[source]==true)continue;
            visited[source]==true;
            result+=weight;
            for(auto v:adj[source])
            {
                if(visited[v[0]]==false)
                {
                    pq.push({v[1],v[0]});
                }
            }
        }
        return result;