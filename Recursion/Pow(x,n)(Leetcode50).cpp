//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

/*
Example:
Input: x = 2.00000, n = 10
Output: 1024.00000

Time complexity:
O(logN)
*/

class Solution {
public:
    double myPow(double x, int n) {

        if(n==0) return 1;  //Anything power 0 equals 1

        //Case when n is negative
        //x^-n = (1/x)^n 
        if(n<0) {
            n = abs(n);
            x = 1/x;
        }

        //Divide the problem into subproblem of size n/2
        if(n%2==0){
            return myPow(x*x, n/2);
        }

        //Firstly, make the size even and then go for even case
        else{
            return x*myPow(x, n-1);
        }
    }
};
