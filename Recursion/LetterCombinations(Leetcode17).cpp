/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

/*Intuition:
Using the concept recursion, we can print the different combinations of alphabets corresponding to each digit provided in the digits string
*/

class Solution {
public:
    void printcombinations(string &digits, vector<string>&letters, char temp[], int index, vector<string>&output) {
        if(index >= digits.length()) {
            temp[index] = '\0'; // Terminate the string with NULL
            string tempa = temp;
            output.push_back(tempa);
            return;
        }

        //Iterate from i=0 uptil number of alphabets in the string
        for(int i=0; i < (letters[digits[index]-'0']).size(); i++) {
            temp[index] = letters[digits[index]-'0'][i];
            //printCombinations for the digit at next index
            printcombinations(digits, letters, temp, index+1, output);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        
        vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        char temp[digits.length() + 1]; // Space for NULL 
        vector<string> output;
        printcombinations(digits, letters, temp, 0, output);
        return output;
    }
};
