//using binary search
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        int n=nums.size();
        map<int,int>m;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;
            int target=-nums[i];
            while(j<k)
            {
                if(nums[k]+nums[j]==target)
                {
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[k]+nums[j]>target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }

            
        }
        vector<vector<int>>triplets;
        for(auto i:ans)
        {
            triplets.push_back(i);
        }
        return triplets;
        
    }
};