/*Best Time to Buy and Sell Stock*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        stack<int>stock_prices;
        stock_prices.push(prices[0]);
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<=stock_prices.top())
            {
                stock_prices.pop();
                stock_prices.push(prices[i]);
            }
            else
            {
                max_profit=max(prices[i]-stock_prices.top(),max_profit);
            }
        }
        return max_profit;
        
    }
};