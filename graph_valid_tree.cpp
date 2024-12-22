class Solution {
public:
    bool checkCycle(int node , vector<vector<int>>&adj_list,vector<bool>&visited)
    {
        queue<int>q;
        q.push(node);
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            if(visited[front]) return true;
            visited[front]=true;
            for(int it: adj_list[front])
            {
               if(visited[it]==false) q.push(it);
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj_list(n);
        int flag=0;
        if(edges.size()==0) return true;
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==edges[i][1]) continue;
            else flag=1;
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        if(flag==0) return false;
        vector<bool>visited(n);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                count++;
                if(count>1) return false;
                if(checkCycle(i,adj_list,visited)) return false;

            }
        }
        return true;

    }
};
