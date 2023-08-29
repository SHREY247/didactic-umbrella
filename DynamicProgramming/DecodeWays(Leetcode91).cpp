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

/* Bottom Top approach

class Solution {
public:
    bool isValid(int code, int len){
            //If length of code is 1, it must be between 1 and 9
            if(len==1){
                return code>=1 && code<=9;
            }

            //If len is 2, code must be between 10 and 26
            return code>=10 && code<=26;
        }
    int numDecodings(string s) {
        int n=s.size();
        int f=isValid(s[0]-'0',1)?1:0;

        //If length of string is 1,  return f that would return 1 if character was valid
        if(n==1){
            return f;
        }

        int s1=0;

        //If code of length 1 is valid at the next index too, add f to s 
        if(isValid(s[1]-'0',1)){
            s1+=f;
        }

        //Now, check for code of length 2
        if(isValid((s[0]-'0')*10+(s[1]-'0'),2)){
            s1++;
        }

        for(int i=2;i<n;i++){
            int curr=0;
            //Check for code of length 1, and add contribution if valid
            if(isValid(s[i]-'0',1)){
                curr+=s1;
            }

            //Check for code of length 2, and add contribution if valid
            if(isValid((s[i-1]-'0')*10+(s[i]-'0'),2)){
                curr+=f;
            }
            f=s1;
            s1=curr;
        }
        return s1;
            
        
    }
};
*/
