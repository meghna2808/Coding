class Solution {
public:
    vector<vector<int>>ans;
    void getSum(int n, int target,vector<int>&temp,int sum,int index)
    {
        if(temp.size()>n || sum>target ) return ;
        if(temp.size()==n)
        {
            if(sum==target)ans.push_back(temp);
            return ;
        }
        for(int i=index;i<=9;i++)
        {
            
                temp.push_back(i);
                getSum(n,target,temp,sum+i,i+1);
                temp.pop_back();
           

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<bool>visited(10, false);
        getSum(k,n,temp,0,1);
        return ans;
        
    }
};