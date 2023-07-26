/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.
*/

class Solution {
public:
   //n needs to be positive because negative power of 2, can never be an integer
   //Also, the bitwise and of n with n-1 is 0 always
   //Example: 2^4 = 16  (10000) and 15 = (01111)
   //10000 && 01111 will always be 0
    bool isPowerOfTwo(int n) {
          if (n > 0 and(n & (n - 1)) == 0) {
                return true;
            }
            return false;
        }        
    }
};
