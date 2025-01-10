class DSU{
    public:
    vector<int>parent,rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    void unionByRank(int i, int j)
    {
        i=findPar(i);
        j=findPar(j);
        if(rank[i]>rank[j])
        {
            parent[j]=i;
        }
        else if(rank[j]>rank[i])
        {
            parent[i]=j;
        }
        else 
        {
            parent[i]=j;
            rank[i]++;
        }
    }
    int findPar(int node)
    {
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node]);
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        map<string,int>emails;
        DSU dsu(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(emails.find(accounts[i][j])!=emails.end())
                {
                    dsu.unionByRank(i,emails[accounts[i][j]]);
                }
                emails[accounts[i][j]]=dsu.findPar(i);

            }
        }
        vector<vector<string>>ans(n);
        for(auto email:emails)
        {
            ans[dsu.findPar(email.second)].push_back(email.first);
            
        }
        vector<vector<string>>final_ans;
        for(int i=0;i<n;i++)
        {
            if(ans[i].size()==0) continue;
            sort(ans[i].begin(),ans[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(string str: ans[i])
            {
                temp.push_back(str);
            }
            final_ans.push_back(temp);

        }
        return final_ans;
        
    }
};