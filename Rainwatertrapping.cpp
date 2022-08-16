//Rain water trapping problem given n bars, calculate rain water that can be trapped
#include <iostream>
#include<limits.h>
using namespace std;
int main() {
    // your code goes here
	long n;
	cin>>n;
	long arr[n];
	for(long i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long pmax[n];
	pmax[0]=arr[0];
	for(long i=1;i<n;i++)
	{
		pmax[i]=max(pmax[i-1],arr[i]);
	}
	long smax[n];
	smax[n-1]=arr[n-1];
	for(long i=n-2;i>=0;i--)
	{
		smax[i]=max(smax[i+1],arr[i]);
	}
	
	long amount = 0;
	for(long i=1;i<n-1;i++)
	{
		long lh=pmax[i-1];
		long rh=smax[i+1];
		
		long deciding_h=min(lh,rh);
		if(deciding_h>arr[i])
		{
			amount += (deciding_h-arr[i]);
		}
	}
	cout<<amount<<endl;
	
    return 0;
}
