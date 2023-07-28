/*
Given an array arr of N integers, and an integer K, Determine whether or not there exist two elements in arr whose sum is exactly K.
 */

#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n,k;
	cin>>n>>k;
	unordered_map<int , int> umap;
	for(int i = 0; i < n ; i ++){
		int x;
		cin>>x;
		//For x, if there exists target - x, output yes
		if(umap[k - x] > 0){
			cout<<"Yes";
			return 0;
		}

    //Add x to to the map or update its frequency if it repeats
		umap[x]++;
	}
	cout<<"No";
    return 0;
}
