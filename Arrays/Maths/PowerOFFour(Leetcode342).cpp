/*
Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4^x.
Example 1:
Input: n = 16
Output: true
Example 2:
Input: n = 5
Output: false
Example 3:
Input: n = 1
Output: true
Constraints:
-231 <= n <= 231 - 1
Intuition
Firstly, we verify if the number is a power of two. Then, we check if number minus one is divisible by three.
Approach
1: (n & (n - 1)) == 0 checks if n is a power of two
2: (n - 1) % 3 == 0 checks if n - 1 is divisible by 3
a) If you subtract 1 from a power of four, you get a number that has all bits set up to and including the position of the '1' bit in the original power of four. For example, for 16 (10000 in binary), subtracting 1 gives 15 (01111 in binary).
b) When you have a binary number where all bits up to a certain position are set (like 01111), it turns out that this number is always divisible by 3.
Complexity
Time complexity:
O(1)
Space complexity:
O(1)
Code
*/


class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};
