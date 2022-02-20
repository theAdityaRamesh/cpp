class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int lastMin = prices[0];
        for(int i = 1; i < prices.size(); i++ ){
            if(prices[i] > lastMin && prices[i] > profit){ // if current stock is more than prev min stock then
                profit = max(profit, prices[i] - lastMin); // sell stock and upadate profit if greatear than current profit
            } else if(prices[i] < lastMin){ // if stock is chepear than current min
                lastMin = prices[i]; // update the min value
            }
        }
        
        return profit;
    }
};
