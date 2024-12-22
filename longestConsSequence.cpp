class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>m;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            m[nums[i]]=true;
        }
        for(int i=0;i<size;i++)
        {
            if(m.find(nums[i]-1)!=m.end())
            {
                m[nums[i]]=false;
            }
        }
        int max_len=0;

        for(int i=0;i<size;i++)
        {
            
            if(m[nums[i]]==true)
            {
                int count=0;
                int j=0;
                while(m.find(nums[i]+j)!=m.end())
                {
                    j++;
                    count++;
                }
                max_len=max(max_len,count);
            }
        }

        return max_len;
    }
};