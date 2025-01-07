#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &intervals){
	// Write your code here.
	int n=intervals.size();
        if(n==0) return {{}};
        int i=1;
        vector<vector<int>>result;
        sort(intervals.begin(),intervals.end());
        result.push_back({intervals[0][0],intervals[0][1]});
        while(i<intervals.size())
        {
            if(intervals[i][0]<=result[result.size()-1][1])
            {
                result[result.size()-1][0]=min(intervals[i][0],result[result.size()-1][0]);
                result[result.size()-1][1]=max(intervals[i][1],result[result.size()-1][1]);
            }
            else result.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        return result;
	
}