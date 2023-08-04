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
	vector<string> ans;
	queue<string> q;
	//Push smallest binary possible in the given range, which is definitely 1 into the queue
	q.push("1");
	int count=0;
	int size=1;
	while(count<N){
	    string val = q.front();
	    q.pop();
	    //Push val into ans
	    ans.push_back(val);
	    count++;
	
	if(size<N){
	    q.push(val + "0");
	    size++;
	}
	
	if(size<N){
	    q.push(val+"1");
	    size++;
	}

	}
	
	return ans;
	
	
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
