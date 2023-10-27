/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

Intuition
The MinStack class is designed to maintain a stack of elements while also keeping track of the minimum element in the stack.

Approach
1: The MinStack class uses a single stack, stk, to store pairs of elements and the minimum values encountered so far.
2: When an element is pushed onto the stack, the current minimum value is calculated by comparing the new element with the minimum value stored on top of the stack. The pair (element, current minimum) is then pushed onto the stack.
3: When an element is popped from the stack, it effectively removes the top pair, effectively reverting to the previous state.
4: The top function returns the first element of the top pair on the stack, and the getMin function returns the second element of the top pair, which represents the current minimum value.

Complexity
Time complexity:
O(1) for all operations

Space complexity:
O(N)

Code
*/
class MinStack {
public:
    //Pair contains the current value and the current minima 
    stack<pair<int,int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val,val});
        }

        else{
            int mini=min(val,stk.top().second);
            stk.push({val,mini});
        }        
    }
    
    void pop() {
        if(!stk.empty()){
            stk.pop();
        }        
    }
    
    int top() {
        return(stk.top().first);        
    }
    
    int getMin() {
        return(stk.top().second);            
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
