/*
Given an array arr of N integers, and a non-negative integer K, count all distinct pairs with difference equal to K, i.e., arr[ i ] - arr[ j ] = K.
*/

#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;
int main() {   
    int n,k,l,r,c;
	cin>>n;
	cin>>k;

	vector <int> v;

	for(int i=0;i<n;i++)
	{
		cin>>c;
		v.push_back(c);
	}
//c tracks count
c=0;
//Sort the vector
sort(v.begin(),v.end());
//Initialize left and right pointer to first and second index
l=0;r=1;

while(l<r&&r<n)
{
int curr=v[r]-v[l];
	
if(curr==k)

{
//If K==0, increment count by 1 as we just need to consider unique pair
//skip elements with same values

if(k==0)
{
	
while(v[l]==v[l+1]&&l+1<n){
//l will be incremented uptil we keep on getting the same values	
l++;
}

//If (l+1)<n, increment l so that it points to the next different element
if(l+1<n)
l++;

//Set the value of r to next element of l
//This is because we are making l and r point to next unique elements	to consider other cases
r=l+1;

//Increase the count by 1	
c++;
}

//When k!=0, check for number of elements whose difference is k
//Example: There are 3 4s and 3 7s and required difference is 3
// We need total cases possible: 9, but we need only unique cases so single unique case, therefore c=c+1
	
else{
while(v[l]==v[l+1]&&l+1<n)
{
l++;
}

	
while(v[r]==v[r+1]&&r+1<n)
{
r++;
}

//Increment count
c=c+1;

//Increment l and r	
l++;
r++;
}

}

//If current difference is less than k, increment r, so that we can try for higher value of curr	
else if(curr<k){
r++;
}

//If curr>k, increment l, this would decrement the value of curr	
else{
l++;
	
//If l equals r, increment r as we shouldn't consider the same element as v[r] and v[l]	
if(l==r)
r++;
}
}

cout<<c<<endl;

    return 0;

 

}

