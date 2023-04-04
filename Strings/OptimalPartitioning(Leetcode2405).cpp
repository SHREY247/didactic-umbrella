/*Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.
Return the minimum number of substrings in such a partition.
Note that each character should belong to exactly one substring in a partition.*/

class Solution {
public:
    int partitionString(string s) {
        int ans=1; //Minimum answer will be 1, i.e. when no partition
        set<char> st;
        for(auto c:s){
            //If you find the character, delete the hashmap and increase the ans
            if(st.find(c)!=st.end()){ /*This line means that you could find character c before reaching the end of set*/
                st.clear();
                ans++;
            }

            //Insert the character
            st.insert(c);
        }
        return ans;
    }
};
