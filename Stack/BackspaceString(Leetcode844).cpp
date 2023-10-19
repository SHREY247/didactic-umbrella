/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.
Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Intuition
Use a stack and keep pushing elements if they are not equal to "#",
and pop the topmost element if "#" is encountered. Check for the equality of the 2 strings after converting them to their final version.

Approach
1: Convert Function (convert):
a) Initialize a stack st to store characters.
b) Loop through each character c in the input string s.
c) If c is a backspace character (#), pop the top element from the stack if it's not empty (effectively removing the previous character).
d) If c is not a backspace character, push it onto the stack.
e) After the loop, construct a string a by popping characters from the stack and appending them to a.
f) Return the final string a.

2: Backspace Compare Function (backspaceCompare):
a) Call the convert function for both strings s and t to get the modified versions.
b) Compare the modified strings s1 and s2.
c) Return true if s1 is equal to s2, otherwise return false.

Complexity
Time complexity:
O(N), N being the length of longer string

Space complexity:
O(N)

Code
*/
class Solution {
public:
    string convert(string s)
    {
        stack<char>st;//stack of characters
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='#')
            {
                if(st.empty()) continue;// if there is nothing to remove
                else st.pop();
            }
            else
                st.push(s[i]);
        }
        string a = "";
        while(st.empty()==false)
        {
            a+=st.top();
            st.pop();
        }
        return a;
    }
    bool backspaceCompare(string s, string t) {
        string s1 = convert(s);
        string s2 = convert(t);
        return s1==s2;
    }
};
