/* using logiv that n&n-1 removes the least sognificant bit that is 1 , so each iteration when 1 is present is counted*/
class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0)
        {
            n=n&n-1;
            count++;
        }
        return count;
        
    }
};
//using shift operator
for(int i=0;i<32;i++)
    {
        if((n>>i) & 1==1)
        {
            count++;
        }
    }
    return count;