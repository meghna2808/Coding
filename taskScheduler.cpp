class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>frequency(26,0);
        for(int i=0;i<tasks.size();i++)
        {
            frequency[tasks[i]-'A']++;
        }

        priority_queue<int>pq;
        for(int i=0;i<26;i++)
        {
            if(frequency[i]>0)
            {
                pq.push(frequency[i]);
                cout<<frequency[i]<<endl;
            } 
        }
        int time=0;
        while(!pq.empty())
        {
            int cycle=n+1;
            vector<int>remain;
            while(cycle>0 && !pq.empty())
            {
                int top=pq.top();
                pq.pop();
                if(top>1)remain.push_back(top-1);
                time++;
                cycle--;

            }
            for(int i=0;i<remain.size();i++)
            {
                pq.push(remain[i]);
            }
            if(pq.empty()) break;
            time+=cycle;
            // cout<<time<<endl;
        }

        return time;
    }
};