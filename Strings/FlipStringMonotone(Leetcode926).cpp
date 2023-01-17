/*A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
Return the minimum number of flips to make s monotone increasing*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
      int countFlip = 0;
      int countOne = 0;
      for(int i = 0 ;i<s.size();i++)
      {
          if(s[i] == '1')
          {
             countOne++; 
          }
          if(s[i] == '0')
          {
              if(countOne>0)
              {
                  countFlip++;
              }
          }
      if(countOne < countFlip)
      {
          countFlip = countOne;
      }
      }
      return countFlip;
    }
};
