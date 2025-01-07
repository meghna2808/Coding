class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1) return 0;
        int count=0;
        sort(intervals.begin(),intervals.end(),compare);
        vector<int>prev=intervals[0];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<prev[1])
            {
                count++;
            }
            else prev=intervals[i];
        }  
        return count;      
    }
};