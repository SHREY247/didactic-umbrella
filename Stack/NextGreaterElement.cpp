/*
Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        //answer vector
        vector<long long> answer(n);
        
        stack<long long> st;
        //We'll keep the stack sorted in descending order from bottom to top
        //Push the index of first element in the stack, because stack with one element will always be sorted
        st.push(0);
        
        //Iterate from 1 to N-1
        for(int i=1;i<n;i++){
            //If the next element in arr is greater than the element at top of the stack and the stack is not empty, assign the next greater element as arr[i] and pop the elements smaller than it
            while(!st.empty() && arr[i]>arr[st.top()]){
                answer[st.top()]=arr[i];
                st.pop();
            }
            
            //Push i into the stack
            
            st.push(i);
        }
        
        
        //Some elements may be left out with no next greater element
        //Set their answer as -1
        while(!st.empty()){
        answer[st.top()]=-1;
        st.pop();
        }
        
        return answer;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
