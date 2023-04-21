/*You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
Return the minimum size of the set so that at least half of the integers of the array are removed.

Example:
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
*/


/*Approach:
1: Priority Queue would have that element at the top whose occurence is maximum
2: Removing such an element would reduce the size faster and count would be as least as possible
3: Firstly, we initialize sum and count as 0, and run while loop until n-sum becomes less than or equal to n/2
4: We update the sum(Which would be sum+q.top()) as at the top of queue, we would be having the count of occurences of element that has come max number of times and increase the count by 1
5: Finally, we return the count after the loop ends.*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        priority_queue<int> q;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        for(auto pair:mp){
            q.push(pair.second);
        }
        int sum=0;
        int cnt=0;
        while(n-sum>n/2){
            sum+=q.top();
            q.pop();
            cnt++;
            
        }
        return cnt;
        
    }
};

