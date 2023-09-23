/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false



Approach
1: Initialize an array count of size 26, all elements set to 0. This array will be used to keep track of the frequency of each character.

2:Loop through string s:
For each character x in s, increment the corresponding counter in the count array. This effectively counts the frequency of each character in s.

3: Loop through string t:
For each character x in t, decrement the corresponding counter in the count array. This effectively subtracts the frequency of each character in t.

4: Loop through the count array:
If any element is non-zero, it means that there are characters with different frequencies in s and t, so the function returns false, indicating that t is not an anagram of s.

5: If the loop completes without returning false, it means that all frequencies are zero, indicating that t is an anagram of s. The function returns true.

Time Complexity
The time complexity of this approach is O(n), where n is the length of the input strings s and t. This is because we iterate through both strings once to update the frequency counters.

Space Complexity
The space complexity is O(1) because the count array has a fixed size of 26 (assuming lowercase English letters).
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] ={0};

        for(char x: s){
            count[x-'a']++;
        }

        for(char x:t){
            count[x-'a']--;
        }

        for(int val: count){
            if(val!=0){
                return false;
            }
        }

        return true;

    }
};
