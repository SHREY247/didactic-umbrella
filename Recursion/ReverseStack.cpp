//Write a program to reverse a stack using recursion. 

/*Approach:
1: Store the topmost stack element in a temporary variable and pop it from the stack
2: Reverse the remaining stack
3: Push the topmost stack element at the bottom of the stack
*/  


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Function to push at bottom of the stack
void pushdown(stack<int>& s,int x)
{
    
//Base Case: If stack is empty, push x    
if(s.empty())
{
s.push(x);
return;
}

//Store the stack top in temp variable and pop it
int temp=s.top();
s.pop();

// Recursive call
pushdown(s,x);

//Push temp back in the stack, after x has been pushed at the bottom
s.push(temp);
}



//Recursive function to reverse the stack
void reverse(stack<int>& s)
{
//Termination condition    
if(s.empty())
return;

//Store the topmost stack element in x
int x=s.top();

//Pop x from the stack
s.pop();

//Call reverse on remaining stack
reverse(s);

//Push x at the bottom of the stack
pushdown(s,x);
}

int main() {
int n;
cin>>n;
stack<int> s;
vector<int> v;
for(int i=0;i<n;i++)
{
int value;
cin>>value;
v.push_back(value);
}

//Push elements in the stack
for(int i=n-1;i>=0;i--)
{
s.push(v[i]);
}

//Call reverse function
reverse(s);

//Print the updated stack
for(int i=0;i<n;i++)
{
int val=s.top();
cout<<val<<" ";
s.pop();
}
cout<<endl;

return 0;

}
