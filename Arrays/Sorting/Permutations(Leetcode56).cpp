/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Intuition
Sort the intervals based on their start times and then iterate through the sorted intervals, merging overlapping ones into a final result.

Approach
1: Sorting: The intervals are sorted based on their start times.
2: Merging Overlapping Intervals:
a) Iterate through the sorted intervals.
b) If the current interval's start time is greater than the end time of the last interval in the answer or if the answer is empty (indicating the first interval), add the current interval to the answer as a new merged interval.
c) If the current interval overlaps with the last interval in the answer, update the end time of the last interval in the answer to accommodate the larger end time between the two overlapping intervals.
3: Return the merged intervals finally

Complexity
Time complexity:
O(N*logN)

Space complexity:
O(N)

Code
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        //Firstly, sort intervals 
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            //If we are pushing the first interval or the next interval's starting is greater than last interval's ending, just push that interval to ans
            if(ans.empty() || intervals[i][0]> ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            //Otherwise, the ending point of last interval would be updated to the maximum of both possible ending points
            else{
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;        
    }
};
