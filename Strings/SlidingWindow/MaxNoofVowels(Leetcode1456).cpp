/*Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
*/

//Sliding window approach

class Solution {
public:
    // Function to check if a character is a vowel
    bool isVowel(char c){
        char t = tolower(c);
        return t == 'a' or t == 'e' or t=='i' or t=='o' or t=='u';
    }
    
    int maxVowels(string s, int k) {
        int n = s.size();
        int start = 0;
        int e = 0;

        int ans = 0;  // Initialize ans containing count of max of vowels to 0
        int temp = 0;  // Initialize a temporary count of vowels in the current window

        // Loop through the string with a sliding window approach
        while(e< n){
            // If the current character is a vowel, increment temp
            if(isVowel(s[e])){
               temp++;
           }
          
           // If the window size is equal to k+1, slide the window by moving the start pointer
           if(e-start == k ){
               //Check if starting character was a vowel or not, if yes, decrement the temp
               if(isVowel(s[start])){
                   temp--;  
               }
               start++;  //Checking for next window of size k
           }
           
           ans = max(ans, temp);  // Update the maximum number of vowels found so far
           e++;  // Move the end pointer to expand the window
        }
        
        return ans; 
    }
};
