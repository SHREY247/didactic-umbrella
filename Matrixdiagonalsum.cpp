/*Given a square matrix mat, print the sum of the matrix diagonals.
Only include the sum of all the elements on the primary diagonal and
all the elements on the secondary diagonal that are not part of the primary diagonal.*/

#include <iostream>
using namespace std;
int main() {
    // n : size of matrix
    cout<<"Enter size of the matrix\n";
    int n;
    cin>>n;
    int A[n][n];
	cout<<"Enter the elements of the matrix row-wise\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    int sum= 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                sum += A[i][j];
            
          	else if((i+j)==(n-1))
                sum += A[i][j];
        }
    }
	cout<<"Sum of all the diagonal elements(including both primary and secondary elements is ";
    cout<<sum<<endl;
    return 0;
}
