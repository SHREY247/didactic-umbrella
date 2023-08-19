/*You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        int carry = 0;
        int sum = 0;
        
        for(int i=n-1; i>=0; i--){
            
            if(i == n-1) {
                sum = digits[i] + 1;
            }else{
                sum = digits[i] + carry;
            }
            
            digits[i] = sum % 10;        
            carry = sum / 10;
        }
        
        if(carry > 0){
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};
