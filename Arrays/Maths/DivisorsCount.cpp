/*
For each test case output a line containing N space separated integers
denoting the number of prime factors of each of the array element.

Example:
Input
1
3
10 12 14
Output
2 2 2
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxm=1e6;
vector<int>spf;
void precompute(){
	spf.resize(maxm+1);
	spf.assign(maxm+1,-1);
	for(int i=2;i<=maxm;i++){
		spf[i]=i;	
	}
	
	//Calculating the shortest prime factors
	for(int i=2;i*i<=maxm;i++){
		if(spf[i]==i){
			for(int j=i*i;j<=maxm;j+=i){
				if(spf[j]==j){
					spf[j]=i;
				}
			}
		}
	}
}
long func(int num){
	
	unordered_map<int,int>mp;
	int n=num;

	//Map to store prime factors and its exponent
	while(n>1){
	 mp[spf[n]]++;
	 n=n/spf[n];
	}
	
 
	//Map's size will be equal to the number of divisors
	return mp.size();
	
}
void solve(){
	int n;
	cin>>n;
   vector<int>arr(n);
 for(int i=0;i<n;i++ ){
	 cin>>arr[i];
 }
for(auto &x:arr){
	long cnt=func(x);
	cout<<cnt<<" ";
}
	cout<<endl;
	
}
int main() {
	int t;
	cin>>t;
	precompute();
	while(t--){
		solve();
	}
    // your code goes here
    return 0;
}

