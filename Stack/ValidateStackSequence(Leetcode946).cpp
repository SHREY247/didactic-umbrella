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
/*Approach:
1: Maintain a stack st.
2: Push the elements into st starting from 0
3: Check if the stack's top is equal to the first element to be popped(for that we maintain iterator i, that iterates over popped),
if yes, then pop that element and increment i.
4: If in the end, all the elements get popped out and the stack gets empty, return true.*/

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

