/*Given a balanced expression, find if it contains duplicate parenthesis or not. A set of parenthesis are duplicate if the same subexpression is surrounded by multiple parenthesis.
Input Format
In the function a balanced string str is passed.
Output Format
Return a true if it contains duplicates else return false.
Sample Input 1
((a+b)+((c+d)))
Sample Output 1
true
Sample Input 2
(((a+(b)))+(c+d))
Sample Output 2
true
Explanation
sample 1: The subexpression "c+d" is surrounded by two
pairs of brackets.
sample 2: The subexpression "a+(b)" is surrounded by two 
pairs of brackets.*/

/*Intuition:
If there is an operator between opening and closing brackets, then no duplicate else there is a duplicate bracket
*/
//Expected Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

bool duplicateParentheses(string str){
    
    stack<char> Stack;
  
    for (char ch : str)
    {
        if (ch == ')')
        {
            char top = Stack.top();
            Stack.pop();
  
            int elementsInside = 0;
            while (top != '(')
            {
                elementsInside++;
                top = Stack.top();
                Stack.pop();
            }
            if(elementsInside < 1) {
                return true;
            }
        }
  
        else
            Stack.push(ch);
    }
  
    return false;
    
}
