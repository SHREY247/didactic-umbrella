//Link to the problem:https://www.codechef.com/problems/MM1803?tab=statement


#include <bits/stdc++.h>
using namespace std;
 
bool isSafe(vector <vector<int>> &grid, int i, int j){
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()){
            if(grid[i][j] != 0) return true;
        }
 
        return false;
    }
 
void solve(vector <vector <int>> &grid, int i, int j, string &path, vector <string> &res){
    
    if(i == grid.size() - 1 && i == j){
        res.push_back(path);
        return;
    }
  
    //Mark as blocked
    grid[i][j] = 0;

     //For Case 'D': increment row number by 1 and generate all possible options
    if(isSafe(grid, i+1, j)){
        path += 'D';
        solve(grid, i+1, j, path, res);
        path.pop_back();
    }

    //For move left: decrement column number by 1
    if(isSafe(grid, i, j-1)){
        path += 'L';
        solve(grid, i, j-1, path, res);
        path.pop_back();
    }  
    
    //For move right: increment column by 1 
    if(isSafe(grid, i, j+1)){
        path += 'R';
        solve(grid, i, j+1, path, res);
        path.pop_back();
    }

    //For move up: decrement row number by 1
    if(isSafe(grid, i-1, j)){
        path += 'U';
        solve(grid, i-1, j, path, res);
        path.pop_back();
    }
 
    grid[i][j] = 1;
    
}
 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <vector <int>> maze(n, vector<int>(n));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> maze[i][j];
            }
        }
        
        vector <string> res;
        string path = "";
        solve(maze, 0, 0, path, res);
        
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << ' ';
        }
        
        cout << '\n';
    }
    return 0;
}
 
