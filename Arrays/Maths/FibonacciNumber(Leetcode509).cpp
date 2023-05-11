/*The Fibonacci numbers,commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number
is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
*/

class Solution {
public:
    int fib(int n) {
        if(n==0||n==1){
            return n;
        }
       int a=0,b=1,ans=0;
        for( int i=1;i<n;i++){
           ans=a+b;
            a=b;
            b=ans;
        }
        return ans;
    }
};
