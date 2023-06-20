/*Given a matrix mat with n*m elements ,you need to find the sum all sub matrices of the given matrix.
  Since the sum could be very large print the sum modulo 10^9+7

Input
First Line contains two integers n,m. Next n lines contains melements for the matrix

Output
Required sum of all sub matrices.

Example 1:
Input:
2 2
1 2
3 4

Output:
40*/


//A submatrice is made up of top left and bottom right corner that defines it
//For a particular i,j :Total options possible for top left would be (i+1)*(j+1)
//Similarly, total options possible for bottom right arr: (N-i)*(N-j)
//Sum would be total choices possible * arr[i][j]



#include <iostream>
#include<math.h>
using namespace std;
int main() {
    // your code goes here
	long long n,m;
	cin>>n>>m;
	long long arr[n][m];
	long long mod = pow(10,9)+7;
	long long i,j;
	for(i =0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	long long sum = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			long long tl=(i+1)*(j+1);
			long long br=(n-i)*(m-j);
			long long m=tl*br;
			sum+=(m%mod*arr[i][j])%mod;
		}
	}
	
	sum=sum%mod;
	cout<<sum<<endl;
    return 0;
}
.
