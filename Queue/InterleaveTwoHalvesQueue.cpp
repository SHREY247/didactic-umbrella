/*Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.
Input Format
In the function an integer queue passed.
Output Format
Return the interleaved queue .
Sample Input
11 12 13 14 15 16 17 18 19 20
Sample Output
11 16 12 17 13 18 14 19 15 20
*/

//Expected Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

queue<int> interLeave(queue<int> q){
    int n=q.size();
	queue<int> q1, q2; 
	//Push the first half elements of q into q1 and pop them from q
	for (int i=0;i<(n/2);i++) { 
		q1.push(q.front()); 
		q.pop(); //Expected Time Complexity: O(2^n)


	} 
	//Push the second half of the elements into q2 and pop them from q 
	for (int i=0;i<(n/2);i++) { 
		q2.push(q.front()); 
		q.pop(); 
	} 
    //Pushing alternatively the elements from q1 and q2 into q
	for (int i=0;i<(n/2);i++) { 
		q.push(q1.front()); 
		q1.pop(); 
		q.push(q2.front()); 
		q2.pop(); 
	} 
    return q;
}
