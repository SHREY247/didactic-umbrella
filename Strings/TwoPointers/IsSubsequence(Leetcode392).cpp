/*Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).


Example:
Input: s = "abc", t = "ahbgdc"
Output: true
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,c=0;
        while(i<s.size() and j<t.size()){
            //If one character matches then check for next character
            if(s[i]==t[j]){
                i++;
                j++;
            }
            //If no match, increment pointer in string t
            else{
                j++;
            }
        }
        //If i is less than s.size() indicates that a few characters have matched but not all 
        if(i<s.size())
        return 0;

    return 1;
    }
};



 
