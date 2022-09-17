/*Given a matrix mat with n*m elements , you need to find the sum all sub matrices of the given matrix. 
Since the sum could be very large print the sum modulo 10^9+7*/

#include <iostream>
#include<math.h>
using namespace std;
int main() {
    
	long long n,m;
	cout<<"Enter number of rows and columns respectively\n";
	cin>>n>>m;
	long long arr[n][m];
	long long mod = pow(10,9)+7;
	long long i,j;
	cout<<"Enter elemets of the matrix\n";
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
	cout<<"Sum of all sub matrices is "<<sum<<endl;
    return 0;
}
