/*The Planet Earth is under a threat from the aliens of the outer space and your task is to defeat an enemy
who is N steps above you (assume yourself to be at ground level i.e. at the 0th level). 
You can take jumps in power of 2. In order to defeat the enemy as quickly as possible you have to reach the Nth step in minimum moves possible.*/

#include<bits/stdc++.h>
using namespace std;

long long convertDecimalToBinary(unsigned long long int n)
{
    long long binaryNumber = 0;
    unsigned long long int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}

int earthLevel(int k)
{
    //your code goes here
    unsigned long long int binaryNumber, sum = 0;
    binaryNumber = convertDecimalToBinary(k);
    
    while (binaryNumber != 0)
    {
        unsigned long long int t;
        t = binaryNumber%2;
        sum = sum + t;
        binaryNumber = binaryNumber/10;
    }
    
    return sum;
}
