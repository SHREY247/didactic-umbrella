/*
Given an array of integers, nums sorted in ascending order, and a target value. 
Print the number of occurrences of the target in the given array.
You must write an algorithm with runtime complexity.
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r < l)
        return -1;
 
    int mid = l + (r - l) / 2;
 
    // If the element is present at the middle
    // itself
    if (arr[mid] == x)
        return mid;
 
    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arr[mid] > x)
        return binarySearch(arr, l, mid - 1, x);
 
    // Else the element can only be present
    // in right subarray
    return binarySearch(arr, mid + 1, r, x);
}
 int countOccurrences(int arr[], int n, int x)
{
    int ind = binarySearch(arr, 0, n - 1, x);
 
    // If element is not present
    if (ind == -1)
        return 0;
 
    // Count elements on left side.
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;
 
    // Count elements on right side.
    int right = ind + 1;
    while (right < n && arr[right] == x)
        count++, right++;
 
    return count;
}

int main() {
    // your code goes here
	int N;
	cin>>N;
	
	int arr[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	
	int T;
	cin>>T;
	while(T--){
		int target;
		cin>>target;
		
		 cout << countOccurrences(arr, N, target)<<endl;
	}
    return 0;
}
