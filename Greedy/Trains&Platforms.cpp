/*
Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    //N represents number of trains
    int n;
    cin>>n;
    int a[n],d[n];
    //Input arrival and departure times
    for(int i=0;i<n;i++){

        cin>>a[i]>>d[i];

    }
    
    //Sort the arrival array
    sort(a,a+n);
    
    //Sort the departure array
    sort(d,d+n);
    
    //2 pointers ti point to a[0] and d[0] for comparison
    int i=0,j=0;
    
    int count=0,ans=0;

    while(i<n){
        //If arrival time is greater than departure time, means a train departs so decrement the count
        if(a[i]>d[j]){
            count--;
            //Increment j, so that j now points to the departure time of next train
            j++;
        }
        
        //Otherwise, increment the count because we would need a platform to accomodate that train
        else{
            count++;
            //Increment i, so that we can check for arrival of next train 
            i++;
        }

        ans=max(ans,count);
    }

    cout<<ans;

    return 0;

}
    
