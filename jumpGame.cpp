class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        int max_jump=0;
        for(int i=0;i<size;i++)
        {
            if(max_jump<i) return false;
            max_jump=max(max_jump,i+nums[i]);
        }
        return true;
        
    }
};