//Leetcode 567
/*Given two strings s1 and s2, print True if s2 contains a permutation of s1, or False otherwise.

In other words, print True if one of s1’s permutations is the substring of s2.*/

#include<iostream>
using namespace std;
bool checkInclusion(string s1, string s2) {
	int m[26] = {0}; //character array
    for(char c : s1) m[c - 'a']++;
    int j = 0, i = 0, total_chars = s1.size();
	while(j < s2.size()){
    if(m[s2.at(j++) - 'a']-- > 0)
    total_chars--;
    if(total_chars == 0) return true;
            //shifting of window
    if(j - i == s1.size() && m[s2.at(i++) - 'a']++ >= 0)
    total_chars++;
        }
        return false;
    }
int main()
{
	int T;
	string s1,s2;
	cin>>T;
	while(T--)
	{
		cin>>s1>>s2;
		if(checkInclusion(s1,s2)==1)
			cout<<"True\n";
		else 
		cout<<"False\n";
		
	}
}

    
    

