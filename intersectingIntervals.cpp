class Solution {
public:
    bool overlap(vector<int>a,vector<int>b)
    {
        int start=max(a[0],b[0]);
        int end=min(a[1],b[1]);
        if(start<=end) return true;
        return false;
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n=firstList.size();
        int m=secondList.size();
        int i=0,j=0;
        vector<vector<int>>ans;
        while(i<n && j<m)
        {
            if(overlap(firstList[i],secondList[j]))
            {
                ans.push_back({max(firstList[i][0],secondList[j][0]),min(firstList[i][1],secondList[j][1])});
            }
            if(firstList[i][1]>secondList[j][1])
                {
                    j++;
                }
            else if(firstList[i][1]<secondList[j][1])
            {
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return ans;
    }

};