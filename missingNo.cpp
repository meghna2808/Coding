class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<bool>missNumbers(n+1,false);
        for(int i=0;i<nums.size();i++)
        {
            missNumbers[nums[i]]=true;
        }
        for(int i=0;i<=n;i++)
        {
            if(missNumbers[i]==false)return i;
        }
        return 0;
        
    }
};