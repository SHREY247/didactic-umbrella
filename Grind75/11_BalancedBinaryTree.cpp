/*
Given a binary tree, determine if it is height-balanced
Example:
Input: root = [3,9,20,null,null,15,7]
Output: true


Intuition
A queue is a data structure that follows the First-In-First-Out (FIFO) principle, while a stack follows the Last-In-First-Out (LIFO) principle. This code uses two stacks (input and output) to simulate a queue. The input stack is used for pushing elements, and the output stack is used for popping and peeking elements.

Approach
1: push(int x): This function simply pushes the element onto the input stack, as this is the only place new elements are added.

2: pop(): If the output stack is empty, it transfers all elements from the input stack to the output stack. This effectively reverses the order of elements so that the oldest element is on top. Then, it pops the top element from the output stack.

3: peek(): Similar to pop(), it first checks if the output stack is empty. If it is, it transfers elements from the input stack to the output stack. Then, it returns the top element of the output stack without removing it.

4: empty(): Returns true if both the input and output stacks are empty, indicating that the queue is empty.

Time Complexity
1: push(int x): O(1) - Pushing an element onto a stack takes constant time.
2: pop(): O(n) in the worst case where n is the number of elements in the queue. This is because if the output stack is empty, it needs to transfer all elements from the input stack to the output stack, which takes O(n) time. However, in most cases, it will be O(1) as it only requires one pop operation.
3: peek(): O(n) in the worst case, similar to pop() because it may need to transfer elements to the output stack. But, in most cases, it will be O(1).
4: empty(): O(1) - Checking if both stacks are empty is a constant time operation.

Code
*/


class MyQueue {
    stack<int> input, output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int x = output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
