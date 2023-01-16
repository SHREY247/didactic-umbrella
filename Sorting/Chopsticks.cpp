/*Given N sticks and an array length where each length[i] represents length of each stick. Your task is to make maximum number
of pairs of these sticks such that the difference between the length of two sticks is at most D.
A stick can't be part of more than one pair of sticks.*/

#include<bits/stdc++.h>
using namespace std;

int pairSticks(vector<int> length, int D)
{
    int n=length.size();
    int flag=0;
    sort(length.begin(),length.end());
    for(int i=1;i<n;){
        if(length[i]-length[i-1]>D){
            i++;
           continue;
          
        }
        else{
            i+=2;
          flag++;
          }
    }
    return flag;
    
}
