class Solution {
public:
    int noOf1s(int n)
    {
        int count=0;
        while(n!=0)
        {
            n=n&n-1;
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>bits;
        for(int i=0;i<=n;i++)
        {
            bits.push_back(noOf1s(i));
        }
        return bits;
        
    }
};