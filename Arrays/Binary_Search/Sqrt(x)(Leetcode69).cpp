/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
  */

class Solution {
public:
    int mySqrt(int x) {
    int start = 0, end = x,ans;
    long long sqr,mid;
		

		//If x is negative, return -1
    if (x < 0)  
    {
        return -1;
    }
     
		//Use binary search with start=0 and end=x as min value of sqrt is 0 and max value possible is n  
    while(start <= end){
        mid = start + (end - start) / 2;
        sqr = mid * mid;

				//If x is a perfect square, we can directly return mid
        if(sqr == x){
            return mid;
        }

				//If mid*mid>x , answer would lie to the left of mid so modify end to mid-1
        else if(sqr > x){
            end = mid - 1;
        }

				//Otherwise, mid*mid<x, mid can be the ans because of the case that sqrt<x<(mid+1)*(mid+1) so we'll store ans=mid and also search for ans in right of mid 

        else{
            ans = mid;
            start = mid + 1;
        }
    }

    return ans;
        
    }
};
