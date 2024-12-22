string getAlienLanguage(vector<string> &dict, int k)
{
    vector<vector<int>>adj_list(k);
    for(int i=0;i<dict.size()-1;i++)
    {
        string s1=dict[i];
        string s2=dict[i+1];
        int len=min(s1.size(),s2.size());
        for(int j=0;j<len;j++)
        {
            if(s1[j]!=s2[j])
            {
                adj_list[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
       
    }

    vector<int>indegree(k);
    for(int i=0;i<k;i++)
    {
        for(auto it: adj_list[i])
        {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<k;i++)
    {
        if (indegree[i] == 0) {
            q.push(i);
            
        }
    }
    // int count=0;
    string ans="";
    while(!q.empty())
    {
        int n=q.size();
        int front=q.front();
        q.pop();
        ans+=char(front+'a');

        // cout<<count<<endl;
        for(auto it: adj_list[front])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }

    }
    return ans;
}