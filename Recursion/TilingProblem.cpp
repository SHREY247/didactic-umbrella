/*You are given N tiles of size 1 x M, There is a floor of size N x M which you have to cover with tiles. 
Find the number of ways the floor can be completely covered if you can place the tiles in both horizontal and vertical manner.*/


#include <iostream>
using namespace std;

int tiles(int n,int m){
    //If n is smaller than m, we have just 1 arrangement
    if(n<m) return 1;
  
	int op1 = tiles(n-1, m);
	int op2 = tiles(n-m, m);
	return (op1 + op2);
}

int tillingProblem(int n, int m){
    return tiles(n, m);
}
