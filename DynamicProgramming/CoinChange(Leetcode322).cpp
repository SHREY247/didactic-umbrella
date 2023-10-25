/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Intuition
Use dynamic programming, greedy approach would fail in some cases

Approach
1: If the amount is less than 1, there are no valid solutions, so it returns 0.
2: Initialize a dynamic programming array minCoinsDP of size amount + 1. Each element of this array represents the minimum number of coins needed to make up that amount. Initialize all elements to INT_MAX except for minCoinsDP[0], which is set to 0 (since no coins are needed to make up 0).
3: For each i from 1 to amount, iterate through the available coin denominations.
a) For each coin denomination coin, check if it's less than or equal to i and if minCoinsDP[i - coin] is not equal to INT_MAX. This means that it's possible to make up the amount i using the coin coin.
b) If the condition is met, update minCoinsDP[i] to be the minimum of its current value and 1 + minCoinsDP[i - coin]. This is because we're considering using one coin of denomination 'coin', so we add 1 to the number of coins needed to make up i - coin.
4: After the loops, if minCoinsDP[amount] is still INT_MAX, it means it's not possible to make up the amount using the provided coins. In this case, return -1.
5: Otherwise, return minCoinsDP[amount] which represents the minimum number of coins needed to make up the given amount.

Complexity
Time complexity:
O(m*n), m being the amount and n being the number of coins

Space complexity:

O(amount)

Code
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //Edge case
        if(amount<1){
            return 0;
        } 

        vector<int> minCoinsDP(amount+1,INT_MAX);
        minCoinsDP[0]=0;

        for(int i=1;i<=amount;i++){
            for(int coin: coins){
                if(coin<=i && minCoinsDP[i-coin]!=INT_MAX){
                    minCoinsDP[i]=min(minCoinsDP[i], 1+minCoinsDP[i-coin]);
                }
            }
        }

        if(minCoinsDP[amount]==INT_MAX){
            return -1;
        }

        return minCoinsDP[amount];

    }
};
