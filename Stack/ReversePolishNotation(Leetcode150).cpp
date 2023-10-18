/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

  Intuition
Reverse Polish Notation (RPN) is basically the postfix notation For example, instead of writing "2 + 3", we write "2 3 +". To evaluate an RPN expression, we can use a stack to keep track of the operands. When encountering an operator, we pop the top two operands from the stack, perform the operation, and push the result back onto the stack.

Approach
1: Initialize a stack (stk) to store operands.
2: Iterate through each token in the input tokens.
a) If the token is not an operator, convert it to an integer and push it onto the stack.
b) If the token is an operator, pop two operands from the stack (a and b).
c) Perform the operation based on the operator (+, -, *, /) and push the result back onto the stack.
3: After processing all tokens, the result will be at the top of the stack. Return it.

Complexity
Time complexity:
O(N)

Space complexity:
O(N)

Code
*/
static unordered_set<string> operations({"+","-","*","/"});
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto t:tokens){
            if(operations.find(t)==operations.end()){
                stk.push(stoi(t));
            }

            else{
                int b=stk.top();
                stk.pop();

                int a=stk.top();
                stk.pop();

                if(t=="+"){
                    stk.push(a+b);
                }

                else if(t=="-"){
                    stk.push(a-b);                                        
                }

                
                else if(t=="*"){
                    stk.push(a*b);                                        
                }

                 else {
                    stk.push(a/b);                                        
                }
            }
        }
        return stk.top();         
    }
};
