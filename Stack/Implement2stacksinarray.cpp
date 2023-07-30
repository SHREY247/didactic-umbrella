/*
Your task is to implement  2 stacks in one array efficiently. You need to implement 4 methods.
push1 : pushes element into first stack.
push2 : pushes element into second stack.
pop1 : pops element from first stack and returns the popped element. If first stack is empty, it should return -1.
pop2 : pops element from second stack and returns the popped element. If second stack is empty, it should return -1.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends



//Actually, we start one stack from one end and another stack from another end
//top1 is initialized to -1 for normal implementation of stack using an array
//But for stack2 we initialize top2 as size of array (Array would be from 0 to size-1 index, so top2 is set one step above
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = size;
    }
    
    
    int st=-1;
    //Function to push an integer into the stack1.
    void push1(int x)
    {
      //Check If it is possible to push, then push    
      if(top1+1<top2){
          arr[top1+1]=x;
          top1+=1;
      }  
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {   
        //Marking st as top2, when push2 is done for first time
        if(st==-1){
            st=top2;
        }
        
        if (top2 - 1 > top1) {
        arr[top2 - 1] = x;
        top2 -= 1;
    }
    
    
    
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        int ans;
        if(top1>=0){
            ans=arr[top1];
            top1--;
        }
        
        else{
            return -1;
        }
        return ans;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        int ans;
        if(top2<st){
            ans=arr[top2];
            top2++;
        }
        
        //Not possible to pop
        else{
            return -1;
        }
        
        return ans;
    }
    
};



//{ Driver Code Starts.

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends
