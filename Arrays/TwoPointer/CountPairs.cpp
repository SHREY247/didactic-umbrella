/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
Input Format

The first line contains two spaced integers N and K denoting the size of the array and the target sum respectively.
The second line contains N space-separated integers denoting the elements of the array.
Output Format

Print the number of pairs whose sum is equal to K.  
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    long long n,k,l,r,c,count=0;
cin>>n;
cin>>k;
vector <int> v;
for(int i=0;i<n;i++)
{
cin>>c;
v.push_back(c);
}

sort(v.begin(),v.end());

l=0;r=n-1;

while(l<r)

{

int curr=v[l]+v[r];

if(curr==k)

{

long long c1=1,c2=1;
//Case when v[l]==v[r] and v[l]+v[r]=K, then we need to pick 2 elements from the total r-l+1 occurences of that element
if(v[l]==v[r])

{
long long c3;
c3=r-l+1;
count=count+c3*(c3-1)/2;
//Break the loop as this would be the last case where l<r	
break;
}

else{
//Case when there are multiple occurences of left and right elements whose sum equals K
//Example there are 2 3s and 2 7s and required sum is 10, so we need to add 2*2 = 4 to the count	
	
while(v[l]==v[l+1])
{
c1++;l++;
}

while(v[r]==v[r-1])
{
c2++;
r--;
}

count=count+c1*c2;

l++;

r--;

}

}

//Curr sum less than k, incremennt left pointer	
else if(curr<k)

l++;

//Else decrement right pointer 	
else

r--;

}

cout<<count<<endl;

    return 0;

}
