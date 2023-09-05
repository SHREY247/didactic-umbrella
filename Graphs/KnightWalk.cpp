/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.
*/



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
       struct cell{
	        int r;
	        int clumn;
	        int dist;
	    };
 
	 cell creat(int row,int cl,int dist){
	       cell c;
	       c.r = row;
	       c.clumn = cl;
	       c.dist = dist;
	       return c;
	    }
    
    //Check whether given cell is valid
    bool isValid(cell c, int n){
	        return(c.r >=1 && c.r <=n && c.clumn >=1 && c.clumn <= n);
	    }
 
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    cell src = creat(KnightPos[0],KnightPos[1],0);
	    //  All possible directions or knight moves taken into account
	    vector<pair<int,int>> directions = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
	    //Every cell is marked unvisited (0 representing unvisited)
	    int visited[N+1][N+1]= {0};
	    queue<cell> q;
	    //Mark the source's cell as visited
	    visited[src.r][src.clumn]=1;
	    //Push src into queue
	    q.push(src);
        
        
        //Normal BFS
	    while(!q.empty()){
	        cell x = q.front();
	        q.pop();
	        //If already at destination, return distance
	        if(x.r == TargetPos[0] && x.clumn == TargetPos[1]){
	            return (x.dist);
	            break;
	        }
 
	        for(int i=0;i<directions.size();i++){
	            //All possible moves from src taken into account
	            cell adj = creat(x.r+directions[i].first, x.clumn+directions[i].second,x.dist+1);
	            //If the cell is valid, and is not visited, mark as visited and push it into queue
	            if(isValid(adj,N)){
	              if(!visited[adj.r][adj.clumn]){
    	            visited[adj.r][adj.clumn] = 1;
    	            q.push(adj);
	            }
	       }
	   }
	  }
 
 
   }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
