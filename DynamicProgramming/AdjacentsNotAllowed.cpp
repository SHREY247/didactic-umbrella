/*
You have a rectangular grid mat of dimension 2 x N. 
  You need to find out the maximum sum such that no two chosen numbers are adjacent, vertically, diagonally or horizontally.
  */


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i, vector<int> &ans, int N, vector<vector<int>>&mat){
        if(i>=N){
            return 0;
        }
        
        if(ans[i]!=-1){
            return ans[i];
        }
        
        int select = max(mat[0][i],mat[1][i])+helper(i+2,ans,N,mat);
        int dont_select=helper(i+1,ans,N,mat);
        
        ans[i]=max(select, dont_select);
        return ans[i];
    }
    int maxSum(int N, vector<vector<int>> mat)
    {
        // code here
        vector<int> ans(N,-1);
        return helper(0,ans,N,mat);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> mat(2, vector<int>(N, 0));
        for(int i = 0;i < 2; i++){
            for(int j = 0; j < N; j++)
                cin>>mat[i][j];
        }
        
        Solution ob;
        cout<<ob.maxSum(N, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
