/*You are given a string s, which contains stars *.
In one operation, you can:
Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.
Note:
The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.

Example:
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
*/

class Solution {
public:
    string removeStars(string s) {
        string ans="";
        //If you encounter a * while traversing, also pop the last element from ans
        //This is the closest non - star element to the left of ans
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                ans.pop_back();
            }
            //Otherwise, insert the character into c
            else{
                ans+=s[i];
            }
            
        }
        return ans;
    }
};
 
