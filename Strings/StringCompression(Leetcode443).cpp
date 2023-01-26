/*Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters in chars:
If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. 
Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done modifying the input array, return the new length of the array.
You must write an algorithm that uses only constant extra space.*/

#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    
	int count_=1;
    string ans;
	
    for(int i=0;i<chars.size();i++)
    {
        while(i<chars.size()-1 && chars[i+1] == chars[i])
        {
            count_++;
            i++;
        }
        ans += chars[i];
        if(count_ == 1)
        {
            continue;
        }
        ans += to_string(count_);
        count_ = 1;
    }
    
     chars.clear();
    
     for(int i=0;i<ans.size();i++)
     {
          chars.push_back(ans[i]);
     } 
 
    return chars.size();
}
