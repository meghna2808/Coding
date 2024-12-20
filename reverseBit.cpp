class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse_int=0;
        for(int i=0;i<32;i++)
        {
            int last_bit=n&1;
            reverse_int=reverse_int<<1 |  last_bit;
            n=n>>1;
        }
        return reverse_int;
        
    }
};