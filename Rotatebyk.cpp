/*You are given an integer array Arr of length N .
 Rotate the array to the right by K steps
 O(1):Space complexity*/
 
#include <iostream>
using namespace std;
void reverseArray(int arr[],int start,int end)
{
	while(start<end)
	{
	int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		start++;
		end--;	
	}
}
int main() {
    // your code goes here
	int n,k;
	cout<<"Enter size of array and k respectively\n";
	cin>>n>>k;
	int arr[n];
	k=k%n;
	cout<<"Enter "<<n<< " elements\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	reverseArray(arr,0,n-1);
	reverseArray(arr,0,k-1);
	reverseArray(arr,k,n-1);
	cout<<"Output array is:\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
    return 0;
}
