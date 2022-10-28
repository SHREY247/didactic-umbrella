/*Rearrange an array so that arr[i] becomes arr[arr[i]] with O(1) extra space*/
#include <iostream>
using namespace std;

// The function to rearrange an array
// in-place so that arr[i] becomes arr[arr[i]].
void rearrange(int arr[], int n)
{
	// First step: Increase all values by (arr[arr[i]]%n)*n
	for (int i = 0; i < n; i++)
		arr[i] += (arr[arr[i]] % n) * n;

	// Second Step: Divide all values by n
	for (int i = 0; i < n; i++)
		arr[i] /= n;
}

// A utility function to print an array of size n
void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	int n;
	cout<<"Enter size of array\n";
	cin>>n;
	int arr[n];
	cout<<"Enter "<<n<<" elements\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}


	cout << "Given array is \n";
	printArr(arr, n);

	rearrange(arr, n);

	cout << "Modified array is \n";
	printArr(arr, n);
	return 0;
}

