/*
Given a string s, return the longest 
palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

  Intuition
We leverage the property of palindromes that they are symmetric around their center. We consider every position in the string as a potential center (both for odd and even length palindromes), then expand outwards from that center to check if a palindrome exists. By doing this, we ensure that we explore all possible palindromes and keep track of the longest one found.

Approach
1: Initialize an empty string res and a variable resLen to keep track of the length of the longest palindromic substring found so far.
2: Loop through each character in the string, considering it as a potential center for a palindrome.
3: For each center position, check for both odd and even length palindromes:
a) For odd length palindromes, expand outward from the center while the characters on both sides are equal.
b) For even length palindromes, consider the center and the next character as the initial left and right positions, then expand outward.
c) Update res and resLen if a longer palindrome is found.
4: After exploring all possible centers, return the longest palindromic substring found (res).

Complexity
Time complexity:
O(N^2)

Space complexity:
O(1)

Code
*/
class Solution {
public:
        string longestPalindrome(string s) {
        string res;
        int resLen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome
            //Considering every position to be the centre of the palindrome
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > resLen) {
                    res = s.substr(left, right - left + 1);
                    resLen = right - left + 1;
                }
                //Expanding outwards to check for even a greater length
                left--;
                right++;
            }

            // Even length
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > resLen) {
                    res = s.substr(left, right - left + 1);
                    resLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return res;
    }
};
