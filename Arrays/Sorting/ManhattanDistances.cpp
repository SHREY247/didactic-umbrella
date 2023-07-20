/*
Given n integer coordinates. The task is to find sum of Manhattan distance between all pairs of coordinates. Answer might be large. Take modulo by 10^9 + 7
Manhattan Distance between two points (x1, y1) and (x2, y2) is:
|x1 – x2| + |y1 – y2| 

Input Format First line contains 1 ≤ n ≤ 10^5 . 
Next n lines contain two integers − 1000 ≤ x , y ≤ 1000 . Output Format Sum of Manhattan distance between every pair of point modulo 10 9 + 7 .
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
long long n,m=pow(10,9)+7;
cin>>n;
	
long long i,j,k,x,y;
long long x_def=0,y_def=0;
long long total_x=0,total_y=0;

vector<int>X(n);
vector<int>Y(n);

for(i=0;i<n;i++){
cin>>x;
X[i]=x;
//Calculate sium of all x coordinates and taking modulo	
total_x=(total_x%m+x%m)%m;

cin>>y;
Y[i]=y;
//Similarly, calculating sum of all y coordinates	
total_y=(total_y%m+y%m)%m;
}

//Sort all the x coordinates	
sort(X.begin(),X.end());

//Similarly, sort the y coordinates
sort(Y.begin(),Y.end());
	
for(i=0;i<n-1;i++){
//Subtract x[i] from total_x
//This is because: Example:
	//Contribution w.r.t x0:
	//(x1-x0) + (x2-x0) + (x3-x0)....
	//This is equal to (x1+x2+x3+.....) - (n-i-1)*xo
	//x1+x2+x3 can be written as total_x-x[i]
	//This is why we modify total_x and total_y as below:
  
total_x =(total_x%m-X[i]%m)%m;
total_y =(total_y%m-Y[i]%m)%m;


//x_def=(x_def + total_x - (n-1-i)*x[i]	)
//Take mod with m
//Similarly, compute y_def	
  
x_def = (x_def %m + (total_x %m - ((n-i-1)*(X[i])%m)%m)%m)%m;
y_def = (y_def %m + (total_y %m - ((n-i-1)*(Y[i])%m)%m)%m)%m;

}

cout<<(x_def%m+y_def%m)%m<<endl;

    return 0;

}

	
