/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Complexity
Time complexity:
O(N)
Space complexity:
O(1)

Code
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Initialize minimum price to the price on the first day and maximumprofit to 0
        int mini_price = prices[0];
        //We won't be doing any transaction if we don't get profit
        int maxprofit=0;
        for(int i=1;i<prices.size();i++){
            //If we get a profit higher than current profit, we update it
            maxprofit=max(maxprofit,prices[i]-mini_price);
            //If we get minimum price even lesser than the current minimum price, we update it
            mini_price=min(mini_price, prices[i]);
        }
        
        return maxprofit;
    }
};
