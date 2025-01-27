class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<bool>visited(n+1,false);
        vector<int>duplicates;
        for(int i=0;i<n;i++)
        {
            if(visited[nums[i]]==true)
            {
                duplicates.push_back(nums[i]);
            }
            else visited[nums[i]]=true;
        }
        return duplicates;
        
    }
};