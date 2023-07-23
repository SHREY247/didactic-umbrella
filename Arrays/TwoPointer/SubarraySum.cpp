/*
Given an unsorted array arr of size n , find a continuous sub-array which adds to a number S.

In case of multiple subarrays, return the subarray which comes first on moving from left to right.
*/

#include <iostream>
using namespace std;
int main() {
	long long t;
	cin>>t;
	while(t--){
    	long long n;
		long long s;
		cin>>n>>s;
		long long arr[n];
		for(int i=0;i<n;i++){
           cin>>arr[i];
		}
		long long i=0;
		long long j=0;
		long long curr=arr[0];
		long long f=0;
		while(i<n and j<n){
		   //if current sum is lesss than s, increment j pointer and add its contribution to curr
           if(curr<s){
			   j++;
			   if(j<n){curr +=arr[j];}
		   }
			//if current sum is greater than s then subtract the contribution of the element at i and then increment i
		   else if(curr>s){
			   curr -=arr[i];
			   i++;
			   //If i becomes > j, increment j, so that i and j point to the same element and then look for subarray from arr[j]
			   if(i>j)	{
                      j++;
					  if(j<n){curr =arr[j];}
			  }
			}
			//If curr==s, increment f 
			else { f++;break; }
		 }
		//If f is true, output the positions 
		if(f){cout<<i+1<<" "<<j+1;}
	    else {cout<<"-1";}
 		cout<<endl;
	 }
    return 0;
}
