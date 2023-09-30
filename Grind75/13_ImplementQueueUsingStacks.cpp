/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false


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
