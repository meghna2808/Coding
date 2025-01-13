class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distance) {
        vector<vector<int>>adj_matrix(n,vector<int>(n,1e6));
        for(int i=0;i<edges.size();i++)
        {
            adj_matrix[edges[i][0]][edges[i][1]]=edges[i][2];
            adj_matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++)
        {
            adj_matrix[i][i]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    adj_matrix[i][j]=min(adj_matrix[i][k]+adj_matrix[k][j],adj_matrix[i][j]);
                }
            }

        }
        map<int,int>m;
        int ans=INT_MAX;
        int city=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                if(adj_matrix[i][j]<=distance) count++;
            }
            if(count<=ans)
            {
                city=i;
                ans=count;
            } 

        }
        return city;

        
    }
};