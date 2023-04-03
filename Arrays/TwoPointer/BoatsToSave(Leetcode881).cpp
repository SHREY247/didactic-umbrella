/*You are given an array people where people[i] is the weight of the ith person,
and an infinite number of boats where each boat can carry a maximum weight of limit.
Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
Return the minimum number of boats to carry every given person.
Example:
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
*/


//Since, we need to find pairs efficiently use two pointer approach
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;
        int n = people.size();
        int l = 0, r = n-1;
        while(l <= r) {
            if(people[l] + people[r] <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
            count++;
        }
        
        return count;
       
    }
};
