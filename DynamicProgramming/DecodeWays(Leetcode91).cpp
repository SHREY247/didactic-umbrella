/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
*/

class Solution {
public:
  //Memoization
        int helper(string s, int index, vector<int> &dp)
        {
            if (index == s.size())
                //No character left
               	//Empty string decoding is empty only so return 1
                return 1;

            //If sub-problem is computed earlier
            if (dp[index] != -1)
               	return dp[index];

            int ans = 0;
            //Solving for single character
            //Check whether the character is zero
            if (s[index] != '0')
                //Add contribution for decodings from the next index
                ans += helper(s, index + 1, dp);
           	

            //Solving for two characters
            //Check whether the characters lie between 10 and 26 (inclusive)
           if (index + 1 < s.size() && ((s[index] == '1') || (s[index] == '2' && s[index + 1] <= '6')))
                ans += helper(s, index + 2, dp);
            return dp[index] = ans;
        }


    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return helper(s, 0, dp);      
    }
};
