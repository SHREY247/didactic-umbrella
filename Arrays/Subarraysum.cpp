/*Given an array arr[] with n elements , you need to find the sum all sub arrays of array arr.
 Since the sum could be very large print the sum modulo 10^9 + 7 */
 
#include <iostream>
#include<math.h>
using namespace std;

int main() {
long long n;
cout<<"Enter n\n";
cin>>n;
long long arr[n];
cout<<"Enter "<<n<<" elements\n";
for(int i=0;i<n;i++){
cin>>arr[i];
}
	
long long sum = 0;
long long mod = pow(10,9)+7;
	
	for(int i=0;i<n;i++){
	sum += (arr[i]*(i+1)*(n-i))%mod;
}
sum=sum%mod;

cout<<"Sum of all subarrays of given array is "<<sum<<endl;
return 0;
}
	
