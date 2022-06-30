//The output aray must be a product of all the elements of the array except the one at position i
#include<bits/stdc++.h>
using namespace std;

void productarr(int arr[],int n)
{
	if(n==1)
	{
		cout<<0;
		return;
	}
	
	//Memory for arrays left[] & right[]
	int* left = new int[sizeof(int) * n];
	int* right = new int[sizeof(int) * n];
	
	//Memory for product
	int* product = new int[sizeof(int)*n];
	
	int i,j;
	
	left[0]=1;
	right[n-1]=1;
	
	//creating left array
	for(i=1;i<n;i++)
	{
	left[i] = arr[i-1] * left[i-1];
	}
	
	//creating right array
	for(j=n-2;j>=0;j--)
	{
	right[j] = arr[j+1] * right[j+1];
	}
	
	//creating product array
	for(i=0;i<n;i++)
	{
	product[i] = left[i]*right[i];
	}
	for(i=0;i<n;i++)
	{
	cout<<product[i]<<" ";
	}
	
		
}
int main()
	{
		int arr[]={1,2,3,4};
		int n=sizeof(arr)/sizeof(arr[0]);
		cout<<"Product array is: \n";
		productarr(arr,n);
		return 0;
	}

