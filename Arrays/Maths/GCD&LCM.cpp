/*Given two numbers A and B
Return their GCD and LCM*/
//Approach: GCD*LCM = A*B
#include <iostream>
using namespace std;
int main() {
    // your code goes here
	long long int A,B;
	cin>>A>>B;
	
	long long int mini=min(A,B);
	long long int maxi=max(A,B);
	long long int temp=0;
	
	while(maxi%mini!=0){
		temp=maxi;
		maxi=mini;
		mini=temp%mini;
	}
	long long int gcd=mini;
	long long int lcm=(A*B)/gcd;
	
	cout<<gcd<<" "<<lcm;
    return 0;
}
