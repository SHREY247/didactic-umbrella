/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram.

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.*/

//Approach:Effective area = (next[i]-prev[i]-1)*height[i] and return maximum area
class Solution {
    vector<int> nextsmall(vector<int>& arr,int n){
         stack<int> s;
    s.push(-1);
        vector<int> ans(n);
        for(int i=arr.size()-1;i>=0;i--){
           
            while(s.top()!=-1&&arr[s.top()]>=arr[i])
            s.pop();
            if(s.empty()){
            ans[i]=arr[i];
            s.push(arr[i]);
            }
            else
            {
            ans[i]=s.top();
            s.push(i);
            
            }
            
        }
        return ans;
    }
    vector<int> prevsmall(vector<int>& arr,int n){
         stack<int> s;
    s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
           
            while(s.top()!=-1&&arr[s.top()]>=arr[i])
            s.pop();
            if(s.empty()){
            ans[i]=arr[i];
            s.push(arr[i]);
            }
            else
            {
            ans[i]=s.top();
            s.push(i);
            
            }
            
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        int n =heights.size();
        vector<int> next(n);
        vector<int> prev(n);
        next=nextsmall(heights,n);
        prev=prevsmall(heights,n);
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1)
            next[i]=n;
             int b=next[i]-prev[i]-1;
             int newarea=l*b;
             area=max(newarea,area);
        }
        return area;
    }
};
