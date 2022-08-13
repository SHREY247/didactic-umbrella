// x is calculated as maximum of p*a[i]+ q*a[j]+r*a[k] for given p,q,r

#include <iostream>
#include<limits.h>
using namespace std;
int main() {
    // your code goes here
	long long n,p,q,r;
	cout<<"Enter n, p, q and r respectively\n";
	cin>>n>>p>>q>>r;
	long long arr[n];
	cout<<"Enter "<<n<<" element(s)\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long long pmax[n];
	pmax[0]=p*arr[0];
	long long rmax[n];
	rmax[n-1]=r*arr[n-1];
	for(int i=1;i<n;i++)
	{
		pmax[i]=max(pmax[i-1],p*arr[i]);
	}
	for(int i=n-2;i>=0;i--)
	{
		rmax[i]=max(rmax[i+1],r*arr[i]);
	}
	
	long long ans = LONG_MIN;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,pmax[i]+rmax[i]+q*arr[i]);
	}
	cout<<"Maximum value of given expression for these values is equal to \n";
	cout<<ans<<endl;
	
    return 0;
}
