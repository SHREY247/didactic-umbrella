/*Given an array arr of size N where every element is in the range from 0 to N-1.
  Rearrange the given array so that arr[i] = j is changed to arr[j] = i.

You must write an algorithm that runs in linear time and uses linear extra space.*/

/*Approach:
Within a single loop, we are trying to store both the old value as well as the newvalue at a particular index
We are storing number at a particular index as:

1: old_val = arr[i]%n   (Here, we get the index where we would keep the expression for new value)
2: arr[old_val] = n*i + arr[old_val]   (CExpression for new value)

Just divide every number by n to get the final answer    (New values)

In this way, we optimize the space*/

#include <iostream>

using namespace std;

int main() {

    long long n;

cin>>n;

long long i;

long long arr[n];

for(i=0;i<n;i++){

cin>>arr[i];

}

for(i=0;i<n;i++){
int old_val=arr[i]%n;
arr[old_val]=n*i+arr[old_val];
}

for(i=0;i<n;i++){
arr[i]/=n;
cout<<arr[i]<<" ";
}
    return 0;

}


