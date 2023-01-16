/*Theodore implements a new strategy game “Defense of a Kingdom”.
On each level a player defends the Kingdom that is represented by a rectangular grid of cells.
The player builds crossbow towers in some cells of the grid.
The tower defends all the cells in the same row and the same column. No two towers share a row or a column.
The penalty of the position is the number of cells in the largest undefended rectangle.*/

#include<bits/stdc++.h>
using namespace std;
 int main() {
     int t;
    cin>>t;
    while(t--){
        int w,h,n;
        cin>>w>>h>>n;
        vector<int> a;
        vector<int> b;
        a.push_back(0);
        b.push_back(0);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            a.push_back(x);
            b.push_back(y);
        }
        a.push_back(w+1);       //To include last column and last row 
        b.push_back(h+1);       // x and y coordinates form 2 lines of the rectangle, other 2 lines are from last row and column
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int mx = 0,my = 0;
        for(int i=0;i<a.size()-1;i++){
            mx = max(mx,a[i+1]-a[i]-1);
            my = max(my,b[i+1]-b[i]-1);
        }
        cout<<mx*my<<endl;
    }
 
    return 0;
}
