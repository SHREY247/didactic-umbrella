/*
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
    vector<string>v;

    queue<string>q;
    //Push smallest binary number possible in the given range into the queue
    q.push("1");
    //Keep track of count how many numbers have been considered	
    int count=0;

    while(count<N){
    //Store the front element of queue into variable x
    string x=q.front();
    //pop that element from the queue
    q.pop();
    //Increment the count
    count++;
     //Push into answer vector the binary representation
    v.push_back(x);

    //Attach 0 to x, push into queue, and generate further possible numbers  
    // 1 0   represents 2	    
    q.push(x+"0");
   
    //Similarly, attach 1 to x, push it into queue, and generate further possible numbers  
    //1 1  represents 3	    
    q.push(x+"1");
}
    return v;	
}


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends
