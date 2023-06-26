//Given an integer n, return the number of prime numbers that are strictly less than n.

/*Example:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.*/

/*Approach
1:Firstly, initialize each number as prime (by setting bool true)
2: Run a loop till square root of n and eliminate the multiples of the prime numbers by setting their bool value false

Complexity
Time complexity:
O(N.log(logN))
because for 2 we would have N/2 multiples that we would be setting to false ,for 3 N/3 multiples and so on...
Adding these up the sum is: log log N
And we run the loop for N times in the worst case*/

class Solution {
public:

    int countPrimes(int n)              
    {
        vector<bool>prime(n+1,true);
        int count=0;
        for(int i=2; i<=sqrt(n); i++)
        {
            if(prime[i])
            {
                for(int j=i; j*i<n; j++)
                {
                    prime[j*i]=false;
                }
            }
        } 
        for(int i=2;i<n;i++)
        {
            if(prime[i])
            count+=1;
        }
        return count;
    }
   
  
};

  
