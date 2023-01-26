/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.*/

class Solution {
public:
    #define pb push_back
    bool isPalindrome(string s) {
        string str{""};     //empty string defined where string to be checked will be put
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])) str.pb(tolower(s[i])); //All alphanumeric chars are put into str
        }

        //Basic program to check palindrome
        int l =0;
        int r = str.length() -1;
        while(l < r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
