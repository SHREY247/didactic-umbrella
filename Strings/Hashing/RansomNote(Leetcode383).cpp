/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Intuition
The code counts the frequency of each character in both strings and checks if there are enough characters in the magazine to construct the ransomNote.

Approach
1: Initialize a vector arr of size 26 (assuming lowercase English letters). This will be used to keep track of the frequency of each character in the magazine.

2: Loop through the characters in the magazine:
For each character, increment the corresponding element in arr.

3: Loop through the characters in the ransomNote:
For each character, decrement the corresponding element in arr.

4: Check if there are any negative values in arr. If so, return false because it means there are characters in the ransomNote that cannot be constructed from the magazine.

5: If all characters in the ransomNote can be constructed, return true.

Complexity
Time complexity:
O(m + n)

Space complexity:
O(1) (constant size of array)

Code
*/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> arr(26);
        for (char i : magazine) {
            arr[i-97]++;
        }
        for (char i: ransomNote){
            arr[i-97]--;
        }
        for (auto i : arr){
            if (i < 0){
                return false;
            }
        }
        return true;
    }
};
