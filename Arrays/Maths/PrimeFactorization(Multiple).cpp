// Given a number N, print all its unique prime factors and their exponents in N
.

#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
	long long int j,k,prime[1000001],spf[1000001];
	for(j=1;j<=1000000;j++){
		//Initialize every number as prime number firstly
		prime[j]=1;
		//Initialize shortest prime factor as -1
		spf[j]=-1;
	}
	
	prime[1]=0;
	spf[1]=1;
	//Implementation of sieve
	//Setting spf,i.e., shortest prime factor
	for(j=2;j*j<=100000;j++){
		if(prime[j]==1){
			for(k=j;k*j<=1000000;k++){
				if(prime[k*j]==1){
					spf[k*j]=j;
					prime[k*j]=0;
				}
			}
		}		
	}
	
	int i,tc;
	cin>>tc;
	for(i=0;i<tc;i++){
		long long int n,x,count=1;
		cin>>n;
		
		vector<long long int> ans;
		while(spf[n]!=-1){
			ans.push_back(spf[n]);
			n=n/spf[n];	
		}
		
	    //If n is not 1, we are left with a prime number, so push that number
		if(n!=1){
			ans.push_back(n);
		}
		
		int size=ans.size();
		//Initialize a 2D vector containing first prime number and exponent
		vector<pair<int, int>> v = {{ans[0], 1}};
		
		//Increase the exponent if that prime factor repeats
		for(int i = 1; i < size; i++){
            if(v.back().first == ans[i]){
                v.back().second++;
            }else{
                v.push_back({ans[i], 1});
            }
		}
			
			 for(auto x : v){
            cout << x.first << " " << x.second << endl;
        }
	}
	
    return 0;
}
