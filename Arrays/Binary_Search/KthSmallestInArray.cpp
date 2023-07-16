/*
Given an array arr[] of size N having no duplicates and an integer K, 
the task is to find the Kth smallest element from the array in constant extra space and the array can’t be modified.
*/


#include <iostream>
#include <climits>
#include <vector>
using namespace std;
//Function to find elements smaller than equal to y
int findSmEl(vector<int> &a, int y) {
	int cnt = 0;
	for(int i : a)
		if(i <= y) 
			cnt++;
	return cnt;
}
 
int kSmallest(vector<int> &a, int k) {
	int l = INT_MAX, h = INT_MIN;
	for(int i : a) {
		l = min(l, i);
		h = max(h, i);
	}
 	
	//Binary search logic
	while(l <= h) {
		int mid = l + ((h - l)/2);
 		
		//If number of elements smaller than equal to mid is less than k, ans would lie to the right of mid 
		//This is because we require at least k elements for the k^th number
		if(findSmEl(a, mid) < k) l = mid + 1;
		
		//If number of elements less than equal to mid >=k
		else {
			//If(number of elements <= mid-1)<k, then mid is the required ans
			if(findSmEl(a, mid - 1) < k) return mid;
			
			//If(number of elements <= mid-1)>= k,then ans lies towards the left of mid
			else h = mid - 1;
		}
	}
 
	return -1;
}
 
int main() {
    int n;
	cin >> n;
	vector<int> arr(n);
	for(int &i : arr) cin >> i;
 
	int k;
	cin >> k;
 
	cout << kSmallest(arr, k);
 
    return 0;
}

