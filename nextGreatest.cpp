class Solution {
public:
    int findNext(vector<int>&nums2,int x)
    {
        int i=0;
        while(i<nums2.size() && nums2[i]!=x)
        {
            i++;
        }
        i++;
        for(int j=i;j<nums2.size();j++)
        {
            if(nums2[j]>x)
            {
                return nums2[j];
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(findNext(nums2,nums1[i]));
        }
        return v;
    }
};