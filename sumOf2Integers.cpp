class Solution {
public:
    int getSum(int a, int b) {
        int sum=a;
        int carry;
        while(b!=0)
        {
            sum=a^b;
            carry=a&b;
            carry=carry<<1;
            b=carry;
            a=sum;
        }
        return a;
        
    }
};