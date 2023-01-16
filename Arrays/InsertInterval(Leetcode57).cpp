/*You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval 
and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals
(merge overlapping intervals if necessary).
Return intervals after the insertion.*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>>ans;

    for(auto interval : intervals)
    {
       if(interval[1]< newInterval[0])
       {
           ans.push_back(interval);
       } 
       else if(interval[0]>newInterval[1])
       {
           ans.push_back(newInterval);
           newInterval = interval;
       }
       else
       {
           newInterval[0] = min(newInterval[0],interval[0]);
           newInterval[1] = max(newInterval[1],interval[1]);
       }
    }

    ans.push_back(newInterval);
    return ans;
    }
};
