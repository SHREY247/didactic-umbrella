/*
There are n stairs,a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top (order does matter).
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
    
    //Top Bottom approach
    //Recursive relation: f(i) = f(i+1) + f(i+2)
    //To reach n th level from i th level, we need to compute for the sum of (i+1)th and (i+2)th 
    public:
    int totalways(long long i,vector<long long>&ways,int n)
    {
        if(i>n)
        return 0;
        
        if(i==n)
        return 1;

        
        if(ways[i]!=-1)
        return ways[i];

        return ways[i] = (totalways(i+1,ways,n) + totalways(i+2,ways,n))%1000000007;
    }


    int countWays(int n)
    {
        // your code here

      vector<long long>ways(n+1,-1);
      long long ans =  totalways(0,ways,n);
      return ans%1000000007;

    }

};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends
