class Solution
{
public:
    int arrangeCoins(int n)
    {
        if (n == 0)
            return n;
        int i = 1;
        int count = 0;
        while (n > 0)
        {
            n = n - i;
            i++;
            if (n >= 0)
                count++;
        }
        return count;
    }
};