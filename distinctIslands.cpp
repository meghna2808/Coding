class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>indegree(numCourses);
        int n=pre.size();
        vector<vector<int>>graph(numCourses);
        for(int i=0;i<n;i++)
        {
            graph[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int count=0;
        vector<int>ans;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            count++;
            ans.push_back(front);
            for(int i=0;i<graph[front].size();i++)
            {
                indegree[graph[front][i]]--;
                if(indegree[graph[front][i]]==0)
                {
                    q.push(graph[front][i]);
                }
            }
        }
        if(count!=numCourses) return {};
        return ans;

        
    }
};