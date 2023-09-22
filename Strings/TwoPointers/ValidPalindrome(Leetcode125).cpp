/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
Approach
1: Ignoring Non-Alphanumeric Characters:
The first step is to create a modified string str that only contains alphanumeric characters in lowercase.
This is done by iterating through each character of s and checking if it's alphanumeric (isalnum). If so, it's appended to str after converting it to lowercase (tolower).

2: Checking for Palindrome:
The code then sets up two pointers, l and r, initially pointing to the start and end of str.
It compares the characters at these positions. If they don't match, it returns false because the string can't be a palindrome.
It then increments l and decrements r to continue checking.

3: Returning the Result:
If the loop completes without finding any non-matching characters, it means the string is a palindrome and the function returns true.

Time Complexity:
Constructing the modified string str takes O(n) time, where n is the length of the input string s.
Checking if str is a palindrome takes O(n/2) time in the worst case.

Overall, the time complexity is O(n).

Space Complexity:
The additional space used in this code is for the string str. The size of str can be at most the same as the size of the input string s.
Therefore, the space complexity is O(n) in the worst case.
*/
Code
class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                str.push_back(tolower(s[i]));
            }
        }


        int l=0;
        int r=str.length()-1;
        while(l<r){
            if(str[l]!=str[r]){
                return false;
            }

            l++;
            r--;
        }
        return true;                
    }
};
