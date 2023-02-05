/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.*/

/*We need to find all those indexes starting from where we find a permutation of p in string s*/
/*Use sliding window approach*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
     if(s.size()<p.size())
      {
          return ans;
      }
      vector<int>v1(26,0); /*In v1 the count of elements present in string p would be marked*/ 
      vector<int>v2(26,0); /*In v2, we take a window size of p's length and check for all the windows */
      for(auto ch: p)
      {
          v1[ch-'a']++;
      }
      int i = 0 , j = 0;
      while(j<s.size())
      {
         v2[s[j]-'a']++;
         if(j-i + 1 == p.size()) // If we have reached a window size of p's length, compare v1 and v2
         {
             if(v1 == v2)
             {
               ans.push_back(i);   //If v1&v2 are equal, push starting index into ans
             }
         }
         if(j-i+1 < p.size())
         {
             j++;   //  If window size is less than p's length increment j
         }
         else //If window size is greater than remove initial element, i.e., the one at i th index 
         {                      
             v2[s[i]-'a']--;
             i++;
             j++;
         }
      } 
      return ans;  
    }
};
