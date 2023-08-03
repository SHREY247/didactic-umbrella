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

  */

/*Average Time Complexity
O(1) for both push and pop operations

Code
*/


class MyQueue {
public:

    //We maintain to stacks, s1 for push operations and s2 for pop operations
    stack <int> s1,s2;
    //front tracks the front element, i.e., that element which would be deleted on pop
    int front;
    int s1_bottom;
    MyQueue() {
        
    }
    
    void push(int x) {
        //If both stacks are empty, update the front variable 
        if(s1.empty() && s2.empty()){
            front=x;
        } 
        
        //If only s1 is empty then update s1_bottom as x
        //This is used to keep the track of the element to be popped if s2 becomes empty
        else if(s1.empty()){
            s1_bottom=x;
        }

        //Push x in stack s1
        s1.push(x);      
    }
    
    int pop() {
        int ans;
        //If s2 is empty, then push the elements from s1 into s2
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
            //Our answer would be the topmost element of stack s2
            //s2.top() would contain the bottom most element of the stack s1, oi.e., that element which needs to be popped
            
            ans=s2.top();
            s2.pop();
        
        
        //Updating the front variable
        
        //If s2 is not empty, update front as topmost element of s2
        if(!s2.empty()){
            front = s2.top();
        }

        else if(!s1.empty()){
            //If s1 was not empty and s2 was empty then front would be bottom most element of s1
            front = s1_bottom;
        }

        return ans;       
    }
    
    int peek() {
        //Front element is the peek element
        return front;        
    }
    
    bool empty() {
        //If both the stacks are empty , return true
        return s1.empty() && s2.empty();        
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
