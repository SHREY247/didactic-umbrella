/*Given a m x n matrix mat and an integer k, 
print a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.*/

#include <bits/stdc++.h>

using namespace std;

int main() {

    int m, n, k;

cin>>m>>n>>k;

int arr[m][n];

for(int i=0; i<m; i++) {

for(int j=0; j<n; j++) {

cin>>arr[i][j];

}

}

//prefix sum matrix

//row wise sum

for(int i=0; i<m; i++) {

for(int j=1; j<n; j++) {

arr[i][j] += arr[i][j-1];

}

}

//col wise sum

for(int i=1; i<m; i++) {

for(int j=0; j<n; j++) {

arr[i][j] += arr[i-1][j];

}

}

int ans = 0;

for(int i=0; i<m; i++) {

for(int j=0; j<n; j++) {

int i1 = i-k, j1 = j-k, i2 = i+k, j2 = j+k;

if(i-k < 0) i1 = 0;

if(j-k < 0) j1 = 0;

if(i+k > m-1) i2 = m-1;

if(j+k > n-1) j2 = n-1;

ans = arr[i2][j2];

if(i1-1 >= 0)

ans -= arr[i1-1][j2];

if(j1-1 >= 0)

ans -= arr[i2][j1-1];

if(i1-1 >=0 && j1-1 >= 0)

ans += arr[i1-1][j1-1];

cout<<ans<<" ";

}

cout<<endl;

}

 

    return 0;

}
