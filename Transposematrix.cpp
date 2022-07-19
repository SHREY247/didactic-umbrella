/*Given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is the matrix flipped over its main diagonal,
switching the matrix row and column indices.*/
#include <iostream>
using namespace std;
int main() {
    // your code goes here
    int n,m;
    cout<<"Enter number of rows and columns of your matrix respectively\n";
    cin>>n>>m;
    int A[n][m];
    cout<<"Enter the elements of the matrix row by row\n";
    for(int i=0;i<n;i++)
    {
		for(int j=0;j<m;j++)
			{
    			cin>>A[i][j];
			}
    }
    
    int ans[m][n];
    for(int i=0;i<n;i++)
    {
		for(int j=0;j<m;j++)
		{
    		ans[j][i] = A[i][j];
		}
     }
           
           cout<<"The transpose of the given matrix is\n";
          for(int i=0;i<m;i++)
    {
			for(int j=0;j<n;j++)
{
    		cout<<ans[i][j]<<" ";
} 
              cout<<endl;
    }
     return 0;
}
