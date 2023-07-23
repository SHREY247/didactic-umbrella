/*
Given an array arr of N integers, and an integer K, Determine whether or not there exist two elements in arr whose difference is exactly K.

Input Format

The first line contains two spaced integers N and K denoting the size of the array and the target difference respectively.
The second line contains N space-separated integers denoting the elements of the array.
*/

#include <bits/stdc++.h>
using namespace std;

void find_pair(vector<int> &nums, int diff)
{
	int i=0, j=1;
	
	while(j<nums.size())
	{
		int d = nums[j]-nums[i];
		if(d==diff)
		{
			cout<<"Yes";
			return;
		}
		//Increment j if d<diff, to check for higher value of d
		if(d<diff) j++;
		else
		{
			i++;
			if(i==j) j++;
		}
	}
	cout<<"No";
}
	
int main() {
    // your code goes here
	int n, diff;
	cin>>n>>diff;
	vector<int> nums(n);
	for(int i=0; i<n; i++)	cin>>nums[i];
	sort(nums.begin(), nums.end());
	find_pair(nums, abs(diff));
    return 0;
}
