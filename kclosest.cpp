class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<float,int>,vector<pair<float,int>>,greater<pair<float,int>>>pq;
        for(int i=0;i<n;i++)
        {
            float dist=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            
            pq.push({dist,i});
        }
        vector<vector<int>>closest;
        while(k>0)
        {
            int index=pq.top().second;
            closest.push_back({points[index][0],points[index][1]});
            pq.pop();
            k--;
        }
        return closest;
        
    }
};