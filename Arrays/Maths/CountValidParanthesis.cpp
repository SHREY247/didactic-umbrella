/*You are given a non-negative number N, find the number of valid parentheses expressions of that length.
  If the answer exists, print the answer modulo 10^9 + 7, otherwise print -1.*/
/*The first line of the input contains a single integer T denoting the number of test cases.
Each test case contains a single integer N.*/
/*Example:
Input
2
4
5
Output
2
-1*/

/*Approach used:
Using the concept of Catalan numbers*/


#include <iostream>
using namespace std;
int main() {
int t,n,i,j;
long long cat[1001];
//cat[i] would be containing i number of pairs of paranthesis
//When 0 pairs of paranthesis: 0 open 0 closed so 1 case valid	
cat[0]=1;
//When 1 pair of paranthesis: ( ) Only this case possible
cat[1]=1;
	
//Example cat[2]: () () or (())	
//Suppose for the first opening paranthesis there are j pairs inside it 
//(n-1-j) pairs would be outside the first closed parantheses
//Subtracting 1 pair for the first paranthesis and j pairs that have come inside the first pair of paranthesis
//Total pairs possible would be: cat[i]+= (cat[j]*cat[i-1-j]) for different values of i and j
	
for(i=2;i<1001;i++){
cat[i]=0;
for(j=0;j<i;j++){
cat[i] = (cat[i] + (cat[j] * cat[i - 1 - j]) % 1000000007) % 1000000007;
}
}
	
cin>>t;
for(i=0;i<t;i++){
cin>>n;
//Odd length can't ever become a valid paranthesis
if(n%2!=0){
cout<<"-1"<<endl;
}

else {
/*we will output cat[n/2] because total length of the string is n 
so it would contain n/2 pairs*/
cout<<cat[n/2]<<endl;
}

}

    return 0;

}
