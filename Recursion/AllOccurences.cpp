/*You are given an integer array of size N. Your aim is to find all the occurrences (indices) of a given element.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
//Solving the problem usig helper function and recursion
void helper(int k,vector<int> v,int i){
    if(i==v.size()){
        return;
    }
    
    if(v[i]==k){
        vec.push_back(i);
    }
    
    helper(k,v,i+1);
    return;
}
vector<int> findAllOccurences(int k, vector<int> v){
    vec.clear();
    helper(k,v,0);
    return vec;
}

