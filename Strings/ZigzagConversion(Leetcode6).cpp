/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R 
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
Example:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
*/


//Solution begins here
//No. of jumps for middle rows will be different from the starting & ending rows
class Solution {
public:
    string convert(string s, int numRows) {             //convert function that takes s and numRows as arguments and has a string return type
        if (numRows == 1) return s;
        string ans = "";    //We take an empty string ans
        for (int i = 0; i < numRows; i++) {         //i is for rows
            int jumps = 2 * (numRows - 1);  //no of jumps to do for reaching the next element of row
            for (int j = i; j < s.length(); j += jumps) {   // j is for columns & increment j always by jumps
                ans += s[j];
                int midJumps = j + jumps - 2 * i;   // jumps for middle rows 
                if (i > 0 && i < numRows - 1 && midJumps < s.length())  // check if middle jumps are in range
                    ans += s[midJumps];
            }
        }
        return ans;
    }
};

