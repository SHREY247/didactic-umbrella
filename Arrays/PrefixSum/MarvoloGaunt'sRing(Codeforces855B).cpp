/*Professor Dumbledore is helping Harry destroy the Horcruxes. He went to Gaunt Shack as he suspected a Horcrux to be present there. He saw Marvolo Gaunt's Ring and identified it as a Horcrux. Although he destroyed it, he is still affected by its curse. Professor Snape is helping Dumbledore remove the curse. For this, he wants to give Dumbledore exactly x drops of the potion he made.
Value of x is calculated as maximum of p·ai + q·aj + r·ak for given p, q, r and array a1, a2, ... an such that 1 ≤ i ≤ j ≤ k ≤ n. Help Snape find the value of x. Do note that the value of x may be negative.
Input
First line of input contains 4 integers n, p, q, r ( - 109 ≤ p, q, r ≤ 109, 1 ≤ n ≤ 105).
Next line of input contains n space separated integers a1, a2, ... an ( - 109 ≤ ai ≤ 109).
Output
Output a single integer the maximum value of p·ai + q·aj + r·ak that can be obtained provided 1 ≤ i ≤ j ≤ k ≤ n.

Examples
inputCopy
5 1 2 3
1 2 3 4 5

Note
In the first sample case, we can take i = j = k = 5, thus making the answer as 1·5 + 2·5 + 3·5 = 30.
.*/





#include <iostream>
#include<limits.h>

using namespace std;

int main() {

long long n,p,q,r;

cin>>n>>p>>q>>r;

long long arr[n];

for(int i=0;i<n;i++)

{

cin>>arr[i];

}

long long pmax[n];

pmax[0]=p*arr[0];

long long rmax[n];

rmax[n-1]=r*arr[n-1];

for(int i=1;i<n;i++)

{

pmax[i]=max(pmax[i-1],p*arr[i]);

}

for(int i=n-2;i>=0;i--)

{

rmax[i]=max(rmax[i+1],r*arr[i]);

}

long long ans = LONG_MIN;

for(int i=0;i<n;i++)

{

ans=max(ans,pmax[i]+rmax[i]+q*arr[i]);

}

cout<<ans<<endl;

    return 0;

}
