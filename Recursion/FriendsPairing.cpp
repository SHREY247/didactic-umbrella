/*Given n friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.*/

#include <iostream>
using namespace std;

int help(int n)
{
    if (n <= 0) return 0;
  //If n is 1 then only person can go single
  // if n=2, 2 ways possible: Both go singly and another way: Both go as a pair
  //If n>2, We'll use recursion 
	if(n == 2 || n == 1) return n;
	return help(n - 1) + (n - 1) * help(n - 2);
}

int friendsPairing(int n){
    
    return help(n);
    
}
