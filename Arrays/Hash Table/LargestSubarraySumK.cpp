/*

Given an array arr of positive and negative integers and an integer K. 
  Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K
*/

#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		
		//Map consists of prefix sum as key and index as value
		unordered_map<int , int> umap;
		int ps = 0;
		int ans = 0;
		//We initialize index for prefix sum of 0 as -1 , to handle empty array
		umap[ps] = -1;
		for(int i = 0; i < n; i ++){
			int x;
			cin>>x;
			ps += x;
			
			//If we find out that there exists a value of ps-k in map, means there is a subarray with sum k
			
			//So ans would be max of initial ans and difference betwwen the indexes where value is ps and where value is ps-k
			//The subarray between these would have a sum k
			if(umap.find(ps - k) != umap.end()){
				ans = max(ans , i - umap[ps - k]);
			}
			
			//Add prefix sum and index to the map
			else{
				umap[ps] = i;
			}
		}
		cout<<ans<<endl;		
	}
    return 0;
}
