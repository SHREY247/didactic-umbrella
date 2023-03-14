/*Given an array and N number of queries, where in each query you have to check 
whether a subset whose sum is equal to given number exists in the array or not.*/

//Use bitset container in C++ using which we can precalculate all the subset sums in an array in O(n) and answer subsequent queries in just O(1).
//Size of bit[] should be at least sum of all array elements plus 1 to answer all queries.

#include<bits/stdc++.h>
using namespace std;

vector<bool> subsetSum(vector<int> v, vector<int> q)
{
    int n = q.size();
    vector<bool> b(n);
    
    bitset<10000> bit;
    bit.reset();
    bit[0] = 1;
  
    for (int i = 0; i < v.size(); ++i)
        bit |= (bit << v[i]);
        
    for(int i=0; i<n; i++)
    {
        int x = q[i];
        bit[x]? b[i]=true : b[i]=false;
    }
    
    return b;
}
