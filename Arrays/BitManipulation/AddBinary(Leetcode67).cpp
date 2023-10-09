/*
Given two binary strings a and b, return their sum as a binary string.
Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

  Intuition
Simulate the addition process just like you would do it by hand, starting from the least significant bit (rightmost bit) and moving towards the most significant bit (leftmost bit).

Approach
1: Initialize variables alen and blen to store the lengths of strings a and b respectively.
2: Initialize i to keep track of the current position being processed and carry to keep track of any carry-over from the previous addition.
3: Initialize an empty string ans to store the result.
4: Use a while loop to iterate over the bits of both a and b as long as there are more bits to process or there is a carry-over from the previous addition.
5: Within the loop, extract the current bit from both a and b (if they exist) and convert it to an integer x and y respectively.
6: Calculate the sum of the current bits along with the carry-over, take the modulo 2 to get the current bit of the result, and append it to the front of the ans string.
7: Update the carry-over for the next iteration, carry=(x+y+carry)/2
8: Move to the next bit by incrementing i.
9: Once the loop ends, return the ans string which contains the binary sum.

Complexity
Time complexity:
O(max(alen,blen))

Space complexity:
O(max(alen,blen))

Code
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int alen=a.length();
        int blen=b.length();
        int i=0, carry=0;
        string ans="";
        
        while (i<alen || i<blen || carry!=0){
            int x=0;
            if (i<alen && a[alen-i-1]=='1'){
                x=1;
            }
            
            int y=0;
            if(i<blen and b[blen-i-1]=='1'){
                y=1;
            }
            ans=to_string((x+y+carry)%2) + ans;
            carry=(x+y+carry)/2;
            i+=1;
        }
        return ans;
            
    }
};
