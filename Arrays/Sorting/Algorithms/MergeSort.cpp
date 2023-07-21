/*
Given an array arr of size n. Sort the array using merge sort algorithm.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//We'll be following divide and conquer technique
//where we would divide the problem into subproblems of size n/2 and keep on dividing further by a factor of 2
//When the subproblem becomes of size 1 start merging them in a sorted manner


//merge function to merge 2 subarrays first starts and ends at s1 and e1 respectively and second one starts and ends at s2 and e2 respectibvely
void merge(vector<int> &v,int s1,int e1,int s2,int e2){
	int i=s1,j=s2,k=0;
	vector<int> tmp(e2-s1+1);
	while(i<=e1 && j<=e2){
		//Place the smaller element into tmp
		if(v[i] <= v[j]){
			
			tmp[k++] = v[i++];
		}
		else{
			tmp[k++] = v[j++];
		}
	}
	
	//If there are some elements left in first subarray, insert those elements in tmp
	while(i<=e1){
		tmp[k++] = v[i++];
	}
	
	//Similarly, if elements are left in second subarray
	while(j<=e2){
		tmp[k++] = v[j++];
	}
	
	//Put elements into vector v
	for(int i=s1;i<=e2;i++){
		v[i] = tmp[i-s1];
	}
}
 
void merge_sort(vector<int> &v,int i,int j){
	int m;
	if(i==j){
		return;
	}
	m = (i+j)/2;
	merge_sort(v,i,m);
	merge_sort(v,m+1,j);
	merge(v,i,m,m+1,j);
}
 
int main() {
    int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	merge_sort(v,0,n-1);
	for(int i=0;i<n;i++){
		cout << v[i] << " ";
	}
    return 0;
}
