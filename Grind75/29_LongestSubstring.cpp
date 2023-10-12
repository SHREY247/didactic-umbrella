/*
Given a string s, find the length of the longest 
substring without repeating characters.
  
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.  
Intuition
Use a sliding window approach

Approach
1: Initialize a map mp to keep track of the frequency of characters in the current window.
2: Initialize pointers l and r to the start of the string.
3: Initialize ans to 0, which will store the length of the longest substring without repeating characters.
4: Iterate r over the string:
a) Increment the frequency of s[r] in mp.
b) If the frequency of s[r] becomes greater than 1, it means there is a repeating character in the current window. In this case, increment the left pointer until the repeating character is removed from the window.
c) Update ans with the maximum length found so far (r - l + 1).
d) Move the right pointer (r) one step forward.
5: Return the ans.

Time Complexity
O(N)

Space Complexity
O(min(n,m)) where n is the length of string and m is size of character set, or the number of possible characters

Code
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        //2 pointers l and r initialized to 0
        int l=0,r=0;

        //map tracks the value and the count
        unordered_map<char,int>m;
        int temp=0;
        while(r<s.size()){
            //If count is 0
            if(m[s[r]]==0){
                //len equala to the length between the indexes i and j
                int len = r-l+1;
                ans = max(ans,len);
                //Increment the count 
                m[s[r]]++;
                //Increment r pointer
                r++;
            }

            //When count is not 0 means that value is already present
            else{
                //Decrement the count for that particular element
                m[s[l]]--;
                //Increment the l pointer, so we wouldn't be considering that particular element
                l++;
            }
        }
        return ans;
    }
};
