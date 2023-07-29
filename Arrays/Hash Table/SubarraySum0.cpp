/*
Given an array arr of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Input Format

The first line contains a single integer T denoting the number of test cases.
The first line of each test case contains a single integer N denoting the size of the array.
The second line of each case contains N space-separated integers denoting the elements of the array.
Output Format

Print "Yes" if such subarray is present in the given array otherwise print "No".
*/

#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		//Map contains prefix sums and their frequency 
		//We add prefix sum of 0 to the map to handle the case when whole array has the sum 0
		unordered_map<int , int> umap;
		umap[0] = 1;
		
		//prefix sum 
		int ps = 0;
		int flag = 0;
		for(int i = 0; i < n ; i ++){
			int x;
			cin>>x;
			ps += x;
		    //If a particular prefix sum is already present in the map, that means the subarray between those two prefix sum has sum 0
		    
		    //So set the flag to 1
			if(umap[ps] > 0){
				flag = 1;
			}
			//Increment the frequency of prefix sum
			umap[ps]++;
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
    return 0;
}
