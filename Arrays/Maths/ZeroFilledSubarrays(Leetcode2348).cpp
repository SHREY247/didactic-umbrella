/*Given an integer array nums, return the number of subarrays filled with 0.
A subarray is a contiguous non-empty sequence of elements within an array.*/

//Time Complexity: O(N)
//Space Complexity: O(1)

/*Here, we store count of continuous 0s and add the count to answer
Example:We get 0,0,0 in an array
count = 1+2+3(1 case for all 3, 2 casees for any 2 0s and 3 cases for single 0 as a subarray) */
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& n) {

        long long int ans = 0, cnt = 0;
        for(int x: n){
            if(x)  //x is non-zero
             cnt=0;
            else 
                cnt++;
            ans+=cnt;
        }
        return ans;
    }
};
