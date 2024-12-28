class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i : m)
        {
            pq.push({i.second,i.first});
        }
        vector<int>topK;
        while(k>0 && !pq.empty())
        {
            topK.push_back(pq.top().second);
            pq.pop();
            k--;

        }
        return topK;
        
    }
};