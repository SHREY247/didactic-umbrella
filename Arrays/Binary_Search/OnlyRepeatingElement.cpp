/*
Given a sorted array of n elements containing elements in range from 1 to n − 1 i.e. one element occurs twice,
the task is to find the repeating element in an array.
Your solution should run in O ( l o g n ) time Input Format The first line of input contains N , 
number of elements in array The second line of input
contains N space-separated integers, n u m s [ 1 ] , n u m s [ 2 ] , ......... n u m s [ N ]
*/

#include <bits/stdc++.h>
using namespace std;
 
int bs(vector<int> &v){
 
	int n=v.size(),l=0,h=n-1;
	while(l<=h){
		int m = (l+h)/2;
		//Corner case: First and second elements are same
		if(m==0){
			if(v[m]==v[m+1])
				return v[m];
			l=m+1;
		}
		
		//Another corner case: Last and second last elements are equal
		else if(m==n-1){
			if(v[m]==v[m-1])
				return v[m];
		}
		//If v[m] is equal to next or previous element return it
		else if(v[m]==v[m+1] || v[m]==v[m-1])
			return v[m];
		
		//v[m]=m happens only when answer is to the left so change high to mid-1
		else if(v[m]==m)
			h=m-1;
		
		//Otherwise, in the left part, v[m]!=m and answer lies to the right
		else
			l=m+1;
	}
	return -1;
}
 
 
int main() {
   	int n;
	cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<bs(v);
    return 0;
}
