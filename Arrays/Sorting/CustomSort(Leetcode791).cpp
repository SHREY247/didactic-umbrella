/*
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
Return any permutation of s that satisfies this property.

EXAMPLE:
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
*/

//Comparator:To sort string s in the ascending order of indexes of the given order string
//In Example 1: c would get index 0, b index 1 and so on....
bool cmp(pair<char,int> a,pair<char,int> b){
       return a.second < b.second;
}

class Solution {
public:

   string customSortString(string order, string s) {
       
       //indexVal to track indexes of characters in the order string (initialized to -1) and changed for the character which is present in the order string
       int indexVal[26] = {-1};

       //Tracking the indexes of characters in the order string 
       for(int i = 0; i < order.size(); i++) indexVal[ order[i] - 'a'] = i;
       
       //Pair takes 1: character of the s string and 2: int to keep track of the index
       vector<pair<char,int>> vec;

       for(int i = 0; i < s.size(); i++)
        //Push into vec the character in s string as well as its index value
        vec.push_back({s[i],indexVal[s[i] - 'a']});

       //Sorting 
       sort(vec.begin(),vec.end(),cmp);

       string res;

       //After the vector is sorted, return res by attaching characters of the sorted string to the result
       for(int i = 0; i < s.size(); i++) res += vec[i].first;

       return res;

   }
};
