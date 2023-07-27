/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //Use bitmask 1<<30
        //When we perform the bitwise AND of numbers between l and r including both of them, we see a pattern
        //If 's' Most significant bits of left are same as 's' Most significant bits of right, they would be same for all the numbers between them

        //So add contributions to ans when you find the bits of both l & r are 1
        unsigned int mask = 1 << 30;
        int ans = 0;
        //check while bits in left and right are same
        while( (left & mask ) == (right & mask) ){
            if(left & mask){
                // If the bit was 1 need to add its contribution to the answer
                ans += mask;
            }
            mask = (mask>>1);
            if(mask == 0) break;
        }
        return ans;
 
    }
};
