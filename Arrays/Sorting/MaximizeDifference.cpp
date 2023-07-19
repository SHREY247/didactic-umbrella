/*
Chef has gone shopping with his 5-year old son. They have bought N items so far. The items are numbered from 1 to N, and the item i weighs Wi grams.
Chef’s son insists on helping his father in carrying the items. He wants his dad to give him a few items. Chef does not want to burden his son. 
But he won’t stop bothering him unless he is given a few items to carry. So Chef decides to give him some items.
Obviously, Chef wants to give the kid less weight to carry.
However, his son is a smart kid. To avoid being given the bare minimum weight to carry, he suggests that the items are split into two groups,
and one group contains exactly K items. Then Chef will carry the heavier group, and his son will carry the other group.
Help the Chef in deciding which items should the son take. Your task will be simple. Tell the Chef the maximum possible difference 
between the weight carried by him and the weight carried by the kid.
*/

//Two possibilities for  K items:
//Choose K smallest items and give those to the kid and remaining to chef
//Choose K largest items and give them to the chef and rest to the kid
//Return the maximum difference possible between these two cases

#include <iostream>
#include <algorithm>
using namespace std;

// return the max value of two numbers
int solve(int array[], int n, int k)
{
	// sort the given array
	sort(array, array + n);

	// Initializing the value to 0
	int sum = 0, sum1 = 0, sum2 = 0;

	// Getting the total sum of the array
	for (int i = 0; i < n; i++) {
		sum += array[i];
	}

	// Getting the sum of smallest k elements
	for (int i = 0; i < k; i++) {
		sum1 += array[i];
	}
	
	//Sorting in descending order
	sort(array, array+n, greater<int>());
	// Getting the sum of k largest elements
	for (int i = 0; i < k; i++) {
		sum2 += array[i];
	}

	// Returning the maximum possible difference.
	//For case 1: sum1: k lighter items weight sum  and (sum-sum1) heavy item weights sum
	//For case 2: (sum2: K largest weight sum, (sum-sum2): Remaining sum of lighter items)
	//Return maximum difference
	return max(abs((sum - sum1)-sum1), abs(sum2 -
								(sum - sum2)));
}

// Driver function
int main()
{
	int T;
	cin>>T;
	while(T--){
		int N,K;
		cin>>N>>K;
		int arr[N];
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}
		cout<<solve(arr,N,K)<<endl;
	}
	
}
