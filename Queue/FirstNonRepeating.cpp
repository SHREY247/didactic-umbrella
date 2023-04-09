/*First Non-Repeating Letter
Given a string, your task is to find first non repeating character at each index otherwise return 0.

Input Format
In the function a vector of character is passed.
NOTE : it will contain only lowercase characters .
Output Format
Return a vector of character.

Sample Input
a a b c
Sample Output
a 0 b b
*/

//Expected Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

vector<char> firstnonrepeating(vector<char> str)
{
	queue<char> q;
    vector<char> v;
	int charCount[MAX_CHAR] = { 0 };

	for (int i = 0; i<str.size(); i++) {

		q.push(str[i]);

		charCount[str[i] - 'a']++;

		while (!q.empty()) {
			if (charCount[q.front() - 'a'] > 1)
				q.pop();
			else {
				v.push_back(q.front());
				break;
			}
		}

		if (q.empty())
			v.push_back('0');
	}
	return v;
}
