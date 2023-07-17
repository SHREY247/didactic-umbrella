/*
Given an integer array nums, sort the array according to frequency of elements. 
That is elements that have higher frequency come first.
If frequencies of two elements are same, then smaller number comes first.
  
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers denoting the elements of the array.
*/

#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;

//Triplet containing value, frequency and index 
struct triplet{
    int val;
    int f;
    int idx;
};


//Comparator function
bool cmp (triplet t1, triplet t2){
	//If frequency of two elements is same, then return smaller value
    if(t1.f == t2.f){
		return t1.val < t2.val;
    }
	
	//Otherwise, return element with higher frequency
    return t1.f > t2.f;
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> num(n);
        for (int i = 0; i < n; i++){
            cin >> num[i];
        }
		//Since nums[i] lies between 1 and 60, so make frequency array of size 61
        vector<int> freq(61);
        for(int i = 0; i < n; i++){
            freq[num[i]]++;
        }
 
        vector<triplet> v;
        for (int i = 0; i < n; i++){
            triplet t;
            t.val = num[i];
            t.f = freq[num[i]];
            t.idx = i;
            v.push_back(t);
        }
        sort(v.begin(), v.end(), cmp);
 
        for (int i = 0;i < v.size(); i++){
            cout << v[i].val << " ";
        }
        cout << endl;
    }
}
