/*
Given a string s, find the length of the longest substring without repeating characters.

Example:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
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
