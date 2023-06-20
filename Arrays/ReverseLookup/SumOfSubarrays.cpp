/*Given an array arr[] with n elements , you need to find the sum all sub arrays of array arr. 
Since the sum could be very large print the sum modulo 10^9+7 

Example 1:
Input:
3 1 2 3
Output:
20
Explanation:
All subarrays are [1], [2], [3],[1,2], [2,3], [1,2,3]. Thus total sum is 20.
*/

//Count the contribution of each element in all the subarrays it is part of
//We get (i+1) options for starting point of subarray and (n-i) options for ending point of the subarray
//Divide by mod because product can be too large

#include <iostream>
#include<math.h>
using namespace std;

int main() {
long long n;
cin>>n;
long long arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
	
long long sum = 0;
long long mod = pow(10,9)+7;
	
	for(int i=0;i<n;i++){
	sum += (arr[i]*(i+1)*(n-i))%mod;
}
sum=sum%mod;
cout<<sum<<endl;
return 0;
}
	

.
