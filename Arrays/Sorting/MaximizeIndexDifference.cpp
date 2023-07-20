/*
Given an array arr of n positive integers. The task is to find the maximum of j - i subjected to the constraint of arr[i] ≤ arr[j] and i ≤ j.

Input Format

The first line of input contains an integer n, denoting the size of array arr.
The next line contains n space-separated integers, denoting elements of array arr.
Output Format

Print maximum index difference (j-i) where arr[i]≤arr[j] and i≤j. print -1 in case no such index is found.
Input 1:

2
1 10
Output 1:
1
*/

#include <bits/stdc++.h>
using namespace std;
//pair consists of two integers, first the value and then the index
//Firstly, sort on the basis of value
//If value is same then sort on the basis of index
bool cmp(pair<int,int> P1,pair<int,int> P2)
{
if(P1.first!=P2.first)
return P1.first<P2.first;
return P1.second<P2.second;
}



int main() {
    int N;
	cin>>N;

	int arr[N];

	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}

	vector<pair<int,int>>vec;
	for(int i=0;i<N;i++)
	{
	vec.push_back({arr[i],i});
	}
//Sort vec
sort(vec.begin(),vec.end(),cmp);

//Initialize ans to 0 because in the output format it is given that i<=j
//so minimum value of j-i will be 0	
int ans=0;
//Suffix max index: initialized to index of last element after sorting	
int suffix_max_idx=vec[N-1].second;
for(int i=N-2;i>=0;i--)
{	
//Update ans and suffix_max_idx	
ans=max(ans,(suffix_max_idx-vec[i].second));
suffix_max_idx=max(suffix_max_idx,vec[i].second);
}

//-1 will never ever be printed	
cout<<ans;
	
	
return 0;

}
