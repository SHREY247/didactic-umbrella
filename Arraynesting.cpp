/*Array Nesting Leetcode 565
You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

The first element in s[k] starts with the selection of the element nums[k] of index = k.

The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.

We stop adding right before a duplicate element occurs in s[k].

Find_the longest length of a set_ s[k].
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
int count=0,ans=INT_MIN;
for(int i=0;i<n;i++){
int ind=a[i];
int currind=i;
while(a[currind]!=-1){
count++;
a[currind]=-1;
currind=ind;
ind=a[currind];
}
if(a[i]==-1){
ans=max(ans,count);
count=0;
}
}
cout<<ans;
return 0;
}
