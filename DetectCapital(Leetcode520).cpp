/* We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right. */

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(isupper(word[0])){
            if(isupper(word[1])){
                for(int i=2;i<word.length();i++){
                    if(islower(word[i])){
                        return false;
                    }
                }
                
            }else{
                for(int i=1;i<word.length();i++){
                    if(isupper(word[i])){
                        return false;
                    }
                }
            }
            
        }else{
            for(int i=0;i<word.length();i++){
                if(isupper(word[i])){
                    return false;
                }
            }
        }
        return true;
    }
};

 
