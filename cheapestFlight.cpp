class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj_list(n);
        for(int i=0;i<flights.size();i++)
        {
            adj_list[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        int stops=0;
        vector<int>price(n,INT_MAX);

        price[src]=0;
        while(!q.empty() && stops<=k)
        {
           int n=q.size();
           for(int i=0;i<n;i++)
           {
                int node=q.front().first;
                int money=q.front().second;
                q.pop();
                for(auto it: adj_list[node])
                {
                    if(money+it.second<price[it.first])
                    {
                        price[it.first]=it.second+money;
                        q.push({it.first,it.second+money});
                        
                    }
                }
           }
           stops++;
        }
        if(price[dst]==INT_MAX) return -1;
        else return price[dst];
    }
};