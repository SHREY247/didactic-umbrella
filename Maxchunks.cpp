/*You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk.
After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    int prefixMaxArray[n];
	int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max= arr[i];
        }
       prefixMaxArray[i]=max;
    }
    
    int chunk=0;
    
    for(int i=0;i<n;i++){
        if(prefixMaxArray[i]==i){
            chunk++;
        }
    }
    cout<<chunk;
    
    return 0;
}
 
