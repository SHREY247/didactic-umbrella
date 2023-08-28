/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. 
According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what 
amount of money but is unable to come up with an optimal looting strategy. 
He asks for your help to find the maximum money he can get if he strictly follows the rule. ith house has a[i] amount of money present in it.
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==0) return 0;
        if(n==1) return arr[0];
        if(n==2) return max(arr[0],arr[1]);
        
        //dp[i] represents maximum stolen value uptil i th house
        int dp[n];
        
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        
        for(int i=2;i<=n;i++){
            //If we consider i th house, add the contribution of current house and contribution uptil (i-2)th house
            //If we don't consider i th house, count the contribution till i-1 th house
            //Return the maximum of two values
            dp[i]=max((arr[i]+dp[i-2]), dp[i-1]);
        }
        
        return dp[n-1];
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
