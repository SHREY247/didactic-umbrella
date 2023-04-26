
//Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
/*
Example:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.*/
/*Approach:
Can be solved using brute force approach but better approach will be mathematical one
1: If number is divisible by 9, then its ultimate sum will be equal   
to 9
2: If not, return num%9, that will be its ultimate sum.
3: Corner case: num=0, we need to return 0 as otherwise it would meet the condition num%9 equals 0 and would return 9
*/

class Solution {
public:
    int addDigits(int num) {
      if(num==0)
          return 0;
      else if(num%9==0)
          return 9;
      else
          return num%9;
    }
};
