/*
Given an array arr of N integers, and an integer K, Determine whether or not there exist two elements in arr whose sum is exactly K.

Input Format

The first line contains two spaced integers N and K denoting the size of the array and the target sum respectively.
The second line contains N space-separated integers denoting the elements of the array.
Output Format

Print "Yes" if there exist two elements in arr whose sum is exactly K otherwise print "No".
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
long long n,k;
cin>>n>>k;
long long arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

sort(arr,arr+n);
//2 pointers i and j 
//where i points to the first element and j points to the last one
long long i=0;
long long j=n-1;
long long f=0;
while(i<j)
{
   long long sum=arr[i]+arr[j];

//If sum is>k, decrement j as that would decrease the value of sum
if(sum>k)
	{j--;
	}
//If sum<k, inncrement i as that would increase the value of sum
else if(sum<k){
	i++;
}

//else sum is equal so increase the count of f and break 
else {
	f++;
	break;
}

}

	//If f>0, return yes
if(f>0){cout<<"Yes"<<endl;}

else {cout<<"No"<<endl;}


    return 0;

}
