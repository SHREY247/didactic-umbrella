/*
Given an array arr of positive and negative numbers. The task is to compute the length of the largest subarray with sum 0. If no subarray of sum 0 is present then output 0.
*/

#include <bits/stdc++.h>
using namespace std;

//  We need to find the index of left most prefix sum and the same prefix sum's rightmost index
int solve(vector<int> &a){
    //map consists of prefix sum and the index uptil which we are considering prefix sum
	unordered_map<int,int> m;
	
	int psum=0,ans=0;
	
	//Initialize prefix sum of empty array as 0 and index as -1
	//This is done to handle the case where sum of overall array is 0
	m.insert({0,-1});
	for(int i=0;i<a.size();i++){
		psum+=a[i];
		//If we find out that the prefix sum doesn't exist, insert the value and index in the map 
		if(m.find(psum)==m.end())
			m.insert({psum,i});
		else
		//If the prefix sum exists, it means the subarray between both these indices has a sum equal to 0
		//ans would correspond to maximum length of such a subarray	
			ans=max(ans,i-m[psum]);
	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		cout<<solve(v)<<endl;
	}
    return 0;
}    
    
 
