class Solution {
public:
    vector<int>getSort(vector<vector<int>>&list,vector<int>&indegree)
    {
        int n=list.size();
        vector<int>sort;
        queue<int>q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            sort.push_back(front);
            for(int neigh:list[front])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)q.push(neigh);
            }
        }
        if(sort.size()==n) return sort;
        return {};

    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //creating separate groups with -1 group ids
        for(int i=0;i<n;i++)
        {
            if(group[i]==-1)
            {
                group[i]=m++;
            }
        }
        vector<vector<int>>itemList(n);
        vector<int>itemIndegree(n,0);
        vector<vector<int>>groupList(m);
        vector<int>groupIndegree(m,0);
        for(int i=0;i<beforeItems.size();i++)
        {
            for(int neigh:beforeItems[i])
            {
                itemList[neigh].push_back(i);
                itemIndegree[i]++;
                if(group[neigh]!=group[i])
                {
                    groupList[group[neigh]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }
        vector<int>itemSort=getSort(itemList,itemIndegree);
        vector<int>graphSort=getSort(groupList,groupIndegree);
        if(itemSort.empty() || graphSort.empty()) return {};
        unordered_map<int,vector<int>>groupMap;
        for(int i=0;i<itemSort.size();i++)
        {
            groupMap[group[itemSort[i]]].push_back(itemSort[i]);
        }
        vector<int>ans;
        for(int i=0;i<graphSort.size();i++)
        {
            for(int item:groupMap[graphSort[i]])
            {
                ans.push_back(item);
            }
        }
        return ans;
    }
};