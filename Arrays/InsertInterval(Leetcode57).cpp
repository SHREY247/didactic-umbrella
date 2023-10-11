/*You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval 
and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals
(merge overlapping intervals if necessary).
Return intervals after the insertion.*/

Intuition
Iterate through the given intervals and performs merging if there is an overlap with the new interval.
If no overlap, just add the interval to the result.

Approach
1: Initialize i to 0 and n to the size of the intervals array. Also, create an empty 2D vector result to store the merged intervals.
2: Iterate through the intervals array using a while loop. For each interval, three cases are considered:
a) If the end of the current interval is before the start of the new interval (intervals[i][1] < newInterval[0]), then it means there is no overlap. Add the current interval to the result.
b) If the start of the current interval is after the end of the new interval (intervals[i][0] > newInterval[1]), then it means there is no overlap with any further intervals. Break out of the loop.
c) Otherwise, there is an overlap, so merge the intervals by updating the start and end of the new interval accordingly (newInterval[0] becomes the minimum of both, and newInterval[1] becomes the maximum of both).

4: After the loop, push the merged newInterval into the result.
5: Iterate through the remaining intervals (if any) and add them to the result.
6: Return the result.

Complexity
Time complexity:
O(N)

Space complexity:
O(1)

Code
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0 ;
        int n = intervals.size();
        vector<vector<int>>result;
        while(i < intervals.size()){
          if(intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
          }
          else if(intervals[i][0] > newInterval[1]){
            break;   
          }
          // merging step 
          else{ 
               //start of merged newInterval would be minimum of starts of both the intervals
               newInterval[0] = min(newInterval[0] , intervals[i][0]);
               end of the merged newInterval would be maximum of both ends  
               newInterval[1] = max(newInterval[1] , intervals[i][1]);
          }
          i++;
        }
        result.push_back(newInterval);

        //If some intervals are left, add them to the result
        while(i < n ){ 
          result.push_back(intervals[i]);
          i++;
        }
        return result;
    }
};
