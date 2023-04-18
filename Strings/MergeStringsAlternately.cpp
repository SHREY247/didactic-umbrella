/*You are given two strings word1 and word2. Merge the strings by adding letters in alternating order,
starting with word1. If a string is longer than the other, append the additional letters onto the end
of the merged string.

Return the merged string

Example:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
*/

/*Approach:
1: Initialize an empty string to store the merged string.
2: Use two pointers to iterate through each character in the two input strings.
3: At each iteration, append the character at the current position of the pointers to the merged string, and increment the pointers.
4: After iterating through the shorter of the two input strings, append any remaining characters in the longer input string to the merged string.
Return the merged string.
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString = "";
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            mergedString += word1[i++];
            mergedString += word2[j++];
        }
        mergedString += word1.substr(i);
        mergedString += word2.substr(j);
        return mergedString;
    }
};

