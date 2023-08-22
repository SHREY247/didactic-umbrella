/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?
Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    
    //pair consists of start times and end times respectively
    //sort on the basis of end times in order to be available for more meetings in the future
    bool static cmp(pair<int,int> &a, pair<int,int>&b){
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i]={start[i],end[i]};
        }
        
        sort(vec.begin(),vec.end(),cmp);
        
        int ans=1;
        int end_time = vec[0].second;
        
        for(int i=1;i<n;i++){
            //If start time of next activity is greater than end time of previous, ans incremented
            //Also, end_time is updated as end_time of the next activity
            if(vec[i].first>end_time){
                ans++;
                end_time=vec[i].second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
