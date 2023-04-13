/*Given two integer arrays pushed and popped each with distinct values,
return true if this could have been the result of a sequence of push and 
pop operations on an initially empty stack, or false otherwise.

Example:
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
*/


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0;
        for(auto val: pushed){
            st.push(val);
            while(st.size()>0 && st.top()==popped[i]){
                st.pop();
                i++;

            }
        }
        return st.size() == 0;
    }
};

