/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example:
Input: s = "()"
Output: true

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s)
        {
            // if element is open parantheses, push it in stack
            if(i=='(' or i=='{' or i=='[')
            st.push(i);
            else
            {
                // checking if top element is opening parantheses
                // of same kind as closing parantheses, if yes then pop else return false
                //Also, return false when no opening parantheses found
                //In this case, stack would be empty
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();
            }
        }
        // If the stack is not empty,that is there is an opening 
        // parentheses without a corresponding closing parentheses and we can return False, else return true.
        return st.empty();
    }
};
