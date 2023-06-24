//Link to the problem: https://www.codechef.com/problems/HMAPPY2

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long func(long long a,long long b){
	long long maxi=max(a,b);
	long long mini=min(a,b);
	
	while(mini){
		long long tmp=maxi;
		maxi=mini;
		mini=tmp%mini;
	}
	long long gc=maxi;
	// lcm=a*b/gcd;
	//long long gc=__gcd(a,b);
	long long lcm=a*b/gc;
	return lcm;
}
void solve(){
	long long n,a,b,k;
	cin>>n>>a>>b>>k;
	long long x=n/a+n/b-2*(n/func(a,b));
	if(x>=k)cout<<"Win"<<endl;
	else cout<<"Lose"<<endl;
}
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		solve();
	}
    // your code goes here
    return 0;
}
