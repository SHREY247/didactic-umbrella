/*
Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, 
the task is to find the number of ways the floor can be tiled. 
A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. Print the answer modulo 10^9+7.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long numberOfWays(long long n) {
        //code here
        //Base case
        //If 2 x 1: Only 1 way possible
        //If 2 x 2: 2 ways possible: 1: Put two 2 x 1 tiles    2: Put 2 1 x 2 tiles
        long long a=1,b=2;
        if(n==1){
            return 1;
        }
        //Place 2 x 1 tile: remaining length: (n-1)
        //Place 2 1 x 2 tiles: remaining length: (n-2)
        for(long long i=3;i<=n;i++){
            long long curr=(a+b)%1000000007;
            a=b;
            b=curr;
        }
        return b%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
