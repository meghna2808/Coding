class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums2[i]);
        }
        set<int>s2;
        for(int i=0;i<nums1.size();i++)
        {
            s2.insert(nums1[i]);
        }
        vector<int>v;
        for(auto i:s2)
        {
            if(s.find(i)!=s.end())
            {
                v.push_back(i);
            }
        }
        return v;
    }
};