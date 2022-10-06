//Leetcode 1456
/*Given a string S and an integer K, print the maximum number of vowel
 letters in any substring of S with length K viven T testcases
*/

#include<bits/stdc++.h>
using namespace std;
int maxVowelsinstring(string s,int k){
	int vowels=0,maxvowel;
	for(int i=0;i<k;i++)
	{
		if(s[i]=='a' || s[i]== 'e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
			vowels++;
	}
	maxvowel=vowels;
	for(int i=k;i<s.length();i++)
	{
		if(s[i]=='a' || s[i]== 'e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
			vowels++;
		
		if(s[i-k]=='a' || s[i-k]== 'e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u' )
			vowels--;
		
		maxvowel = max(vowels,maxvowel);
	}
	return maxvowel;
	
}
int main() {
    // your code goes here
	int T;
	cin >> T; 
	while (T--) {
    string s;
    int k;
    cin >> s >> k;
    cout << maxVowelsinstring(s, k) << endl;
  }
	
	
    return 0;
}
