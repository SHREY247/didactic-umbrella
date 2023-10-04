/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
  Intuition
Case: Odd Frequency Greater than 2
When we encounter a character with an odd frequency greater than 2, it means we can use all but one has to be left of those characters to create a palindrome. For example, if we have 5 'a' characters, we can use 4 of them to form 'aa' in the palindrome, leaving 1 'a' unused.
So, we subtract 1 from the odd frequency (e.g., 5 becomes 4) and add it to sum. This ensures that we are counting all the characters except one from this group in our palindrome.
We set a to 1 to indicate that there is at least one character with an odd frequency in the string.

Case: Odd Frequency (but not greater than 2)
When we encounter a character with an odd frequency but it's not greater than 2(frequency is 1), it means we can use all of these characters in the palindrome.
We set a to 1 to indicate that there is at least one character with an odd frequency in the string.

Case: Even Frequency
When we encounter a character with an even frequency, it means we can use all of these characters in the palindrome.
We simply add the even frequency to sum.

Approach
1: It starts by initializing an unordered map mp to store the frequency of each character in the string s.
2: It then iterates through the characters in s, incrementing the corresponding frequency count in the map.
3: It maintains two variables: sum to keep track of the total count of characters that can be used in the palindrome, and a to indicate if there is at least one character with an odd frequency.
4: It then iterates through the map, checking the frequency of each character:
5: If the frequency is odd and greater than 2, it subtracts 1 from the frequency and adds it to sum. It also sets a to 1.
6:If the frequency is odd, it sets a to 1.
7: If the frequency is even, it adds it to sum.
8: Finally, it returns sum + a which represents the length of the longest possible palindrome.

Complexity
Time complexity: O(N)

Space complexity:
O(N)

Code
*/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(char ch : s)mp[ch]++;
        int sum=0;
        int a=0;
        for(auto x : mp)
        {
            if(x.second%2==1 and x.second>2){
                sum+=x.second-1;
                a=1;
            }
            else if(x.second&1)a=1;
            else if(x.second%2==0)sum+=x.second;
        }
        return sum+a;
    }
};
