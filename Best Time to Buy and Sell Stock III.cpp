class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        vector<int>prefix_sum(size,0);
        stack<int>stocks;
        stocks.push(prices[0]);
        int max_profit=0;
        for(int i=1;i<size;i++)
        {
            if(stocks.top()<prices[i])
            {
                max_profit=max(max_profit,prices[i]-stocks.top());
            }
            else
            {
                stocks.pop();
                stocks.push(prices[i]);
            }
            prefix_sum[i]=max_profit;
        }
        stocks.pop();
        stocks.push(prices[size-1]);
        int max_sum=0;
        max_profit=0;
        for(int i=size-2;i>=0;i--)
        {
            if(stocks.top()>prices[i])
            {
                max_profit=max(max_profit,stocks.top()-prices[i]);
            }
            else
            {
                stocks.pop();
                stocks.push(prices[i]);
            }
            max_sum=max(max_profit+prefix_sum[i],max_sum);
        }
        return max_sum;
        
        
    }
};