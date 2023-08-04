/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
 */

class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    //We'll be fixing the back end of the queue as the single end of the stack
    //To implement push, we can directly push the element at the back end of the queue
    void push(int x) {
        q.push(x);                                
    }
    
    //To implement pop, we need to pop all the elements of the queue until only the element
    //In a stack, we pop out the topmost element, w.r.t., queue we need to pop the element at the front
    int pop() {
        //Initialize a temporary queue
        queue<int> tmp;
        while(q.size()>1){
            //To retain the order of queue, we need to use a queue again
            tmp.push(q.front());
            q.pop();
        } 
        //Now the front of queue would be the element to be popped
        int ans=q.front();
        q.pop();
        
        //q=tmp, now queue will be updated with the required element popped out
        q=tmp;
        return ans;               
    }
    
    int top() {
        //Since, we have fixed the back end of the queue
        return q.back();        
    }
    
    bool empty() {
        //If the queue is empty, stack would surely be empty
        return q.empty();        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
