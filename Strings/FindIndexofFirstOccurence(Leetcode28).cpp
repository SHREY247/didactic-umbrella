//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

class Solution {
public:
    int strStr(string haystack, string needle) {
      int n1 = haystack.size();
      int n2 = needle.size();
      if(n2>n1)
      {
          return -1;
      }
    //Using 2 pointer Technique
    int j = 0; //j points to string needle
    int i = 0; // i points to sting haystack
    int start = 0; 
    while(i < n1 && j < n2)
    {
        if(haystack[i] == needle[j])
        {
          if(i-start+1 == n2) 
          {
              return start;
          } 
          j++;
          i++;
        }
        else
        {
          j=0;
          start++;
          i = start;
        }
    }
    return -1;
}
};
