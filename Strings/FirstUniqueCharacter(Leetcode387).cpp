/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example:
Input: s = "leetcode"
Output: 0*/

/*Approach
1: Store the frequency of each alphabet in the string
2: Traverse the string and return the first element whose count is 1
3: If no such element found, return -1*/

class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = s.length();
        vector<int> frequency(26,0);
        
        //Store frequency of all characters
        for(int i=0;s[i]!='\0';++i)
            frequency[s[i]-'a'] +=1;
        
        //Now traverse and find the first non-repeating char
        for(int i=0;s[i]!='\0';++i)
            if(frequency[s[i]-'a']==1)
                return i;
        
        return -1;     //All chars are repeating
    }
};
