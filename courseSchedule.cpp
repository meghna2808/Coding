class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int size=pre.size();
        vector<int>indegree(numCourses,0);
        vector<vector<int>>graph(numCourses);
        for(int i=0;i<size;i++)
        {
            indegree[pre[i][1]]++;
            graph[pre[i][1]].push_back(pre[i][0]);
            graph[pre[i][0]].push_back(pre[i][1]);
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
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int front=q.front();
                count++;
                q.pop();
                for(int j:graph[front])
                {
                    indegree[j]--;
                    if(indegree[j]==0)q.push(j);
                }

            }
        }
        if(count==numCourses) return true;
        else return false;
        
    }
};