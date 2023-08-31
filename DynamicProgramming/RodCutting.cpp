/*
Given a rod of length N inches and an array of prices, price[].
price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
 */


//Top Bottom approach
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int helper(vector<int> &ans, int price[], int n){
        if(n==0) return 0;
        //Check if alredy computed
        if(ans[n]!=-1) return ans[n];
        for(int j=1;j<=n;j++){
            //ans[n] would be the maximum possible value considering the price[j-1] representing price of length j and answer computed for length of (n-j) 
            ans[n]=max(ans[n],price[j-1]+helper(ans,price,n-j));
        }
        return ans[n];
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int> ans(n+1,-1);
        int answ=helper(ans,price,n);
        return answ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends



/* Bottom Top

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            int max_value = -1;
            for (int j = 1; j <= i; ++j) {
                max_value = max(max_value, price[j - 1] + dp[i - j]);
            }
            dp[i] = max_value;
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

*/
