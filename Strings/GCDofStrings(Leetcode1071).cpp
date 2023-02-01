/*For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.*/


//GCD would only exist if s1+s2 is equal to s2+s1
//eg: AB + ABAB : would be eligible
//ABC + ABCD : Not eligible as we can't divide both strings
// If it is not equal then 
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)? 
        str1.substr(0, gcd(size(str1),size(str2))): "";     //Return the part of string from [0,gcd(size(s1),size(s2)))
    }
};
