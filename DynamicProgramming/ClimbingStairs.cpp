/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

1: Using Dynamic Programming
Intuition
We use dynamic programming to store the results of subproblems in an array dp, where dp[i] represents the number of distinct ways to reach the i-th step.

Approach
1: The base cases are handled first. If n is 0 or 1, it means there's only one way to climb (not taking any steps or taking just one step), so both dp[0] and dp[1] are initialized to 1.

2: A vector dp of size n+1 is created to store the number of ways to reach each step.

3: The loop starts from step 2 and iterates up to step n.

4: Inside the loop, dp[i] is calculated as the sum of the number of ways to reach the previous step (dp[i-1]) and the step before that (dp[i-2]).

5: After the loop, dp[n] contains the number of distinct ways to reach the top of the staircase with n steps.

6: The function returns dp[n].

Complexity
Time complexity:
O(N)

Space complexity:
O(N)

Code
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

