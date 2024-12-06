/*Best Time to Buy and Sell Stock II*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int max_profit=0;
        stack<int>stocks;
        stocks.push(prices[0]);
        for(int i=1;i<size;i++)
        {
            if(prices[i]>stocks.top())
            {
                max_profit+=(prices[i]-stocks.top());
                stocks.pop();
                stocks.push(prices[i]);
            }
            else
            {
                stocks.pop();
                stocks.push(prices[i]);
            }
        }
        return max_profit;
    }
};