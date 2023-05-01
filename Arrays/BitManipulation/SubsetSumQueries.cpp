/*Given an array arr[] and a number of queries, where in each query we have to check whether
a subset whose sum is equal to given number exists in the array or not. 

Example:
Input : arr[]   = {1, 2, 3};
        query[] = {5, 3, 8}  
Output : Yes, Yes, No
There is a subset with sum 5, subset is {2, 3}
There is a subset with sum 3, subset is {1, 2}
There is no subset with sum 8.


Approach:
The idea is to use bitset container in C++. Using bitset, we can precalculate the existence 
all the subset sums in an array in O(n) and answer subsequent queries in just O(1). We basically 
use an array of bits bit[] to represent the subset sum of elements in the array. Size of bit[] 
should be at least sum of all array elements plus 1 to answer all queries. */

// C++ program to answer subset sum queries using bitset
#include <bits/stdc++.h>
using namespace std;

// Maximum allowed query value
# define MAXSUM 10000

// function to check whether a subset sum equal to n
// exists in the array or not.
void processQueries(int query[], int nq, bitset<MAXSUM> bit)
{
// One by one process subset sum queries
for (int i=0; i<nq; i++)
{
int x = query[i];

// If x is beyond size of bit[]
if (x >= MAXSUM)
{
cout << "NA, ";
continue;
}

// Else if x is a subset sum, then x'th bit
// must be set
bit[x]? cout << "Yes, " : cout << "No, ";
}
}

// function to store all the subset sums in bit vector
void preprocess(bitset<MAXSUM> &bit, int arr[], int n)
{
// set all the bits to 0
bit.reset();

// set the 0th bit because subset sum of 0 exists
bit[0] = 1;

// Process all array elements one by one
for (int i = 0; i < n; ++i)

// Do OR of following two
// 1) All previous sums. We keep previous value
// of bit.
// 2) arr[i] added to every previous sum. We
// move all previous indexes arr[i] ahead.
bit |= (bit << arr[i]);
}

// Driver program
int main()
{
int arr[] = {3, 1, 5};
int query[] = {8, 7};

int n = sizeof(arr) / sizeof(arr[0]);
int nq = sizeof(query) / sizeof(query[0]);

// a vector of MAXSUM number of bits
bitset<MAXSUM> bit;

preprocess(bit, arr, n);
processQueries(query, nq, bit);

return 0;
}


