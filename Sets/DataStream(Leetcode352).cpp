/*Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.
Implement the SummaryRanges class:
SummaryRanges() Initializes the object with an empty stream.
void addNum(int value) Adds the integer value to the stream.
int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. 
The answer should be sorted by starti.*/

class SummaryRanges {
public:
    set<int>nums;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
      nums.insert(value);  
    }
    
    vector<vector<int>> getIntervals() {
     vector<vector<int>>res;
     int start = -1,end = -1;
     for(auto &ele : nums)
     {
       if(start == -1)
       {
           start = ele;
           end = ele;
       }
      else if(ele == end+1)
       {
           end = ele;
       }
       else
       {
           res.push_back({start,end});
           start = ele;
           end = ele;
       }

     }
     //For last element 
     if(start!=-1)
     {
         res.push_back({start,end});
     }
     return res;

    }
};
 
