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

class MinStack {
public:
//Stack of type pair
//First one points to the value
//Second one points to the current minima
stack<pair<int , int>> stk;
    MinStack() {
        stack<pair<int , int>> stk;
    }
 
    void push(int val) {
        //If empty stack, push value and the minima would be same as value for only 1 element in the stack
        if(stk.empty()){
            stk.push({val , val});
        }
        //Push current element and the current minima
        else{
            int mn = min( val , stk.top().second);
            stk.push({val , mn});
        }
    }
 
    void pop() {
        if(!stk.empty()) stk.pop();
    }
 
    int top() {
        return(stk.top().first);
    }
 
    int getMin() {
        return stk.top().second;
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
