class Solution {
public:
    void checkVisited(vector<vector<int>>&adj_list, vector<bool>&visited,int index)
    {
        if(visited[index]==true) return ;
        visited[index]=true;
        for(int it:adj_list[index])
        {
            checkVisited(adj_list,visited,it);
        }
        return ;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int size=edges.size();
        vector<bool>visited(n,false);
        vector<vector<int>>adj_list(n);
        for(int i=0;i<size;i++)
        {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                count++;
                checkVisited(adj_list,visited,i);
            }
        }
        return count;

    }
};
