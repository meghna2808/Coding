class Solution {
public:
    static bool comp(pair<int,int>&a, pair<int,int>&b)
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size=nums.size();
        map<int,int>m;
        for(int i=0;i<size;i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int,int>>v(m.begin(),m.end());

        sort(v.begin(),v.end(),comp);
        vector<int>frequent;
        int i=0;
        while(k>0)
        {
            frequent.push_back(v[i].first);
            i++;
            k--;

        }
        return frequent;
        
    }
};