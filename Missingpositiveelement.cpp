/*Given an array of integers, find the first missing positive integer in
linear time and constant space. In other words, find the lowest positive integer
that does not exist in the array. The array can contain duplicates and negative numbers as well.*/
#include <bits/stdc++.h>
using namespace std;

int firstmissingpos(int A[], int n)
{

	// To mark the occurrence of elements
	bool present[n + 1] = { false };

	// Mark the occurrences
	for (int i = 0; i < n; i++) {

		if (A[i] > 0 && A[i] <= n)
			present[A[i]] = true;
	}

	// Find the first element which didn't appear in the original array
	for (int i = 1; i <= n; i++)
		if (!present[i])
			return i;

	// If the original array was of the type {1, 2, 3} in its sorted form
	return n + 1;
}

// Driver code
int main()
{
	int n;
	cout<<"Enter size of array\n";
	cin>>n;
	int A[n];
	cout<<"Enter "<<n<<" elements\n";
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	
	cout<<"First missing positive integer in the given array is "<<firstmissingpos(A,n);
}
