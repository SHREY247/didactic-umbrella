/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job
*/

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool comp(Job &a , Job &b){
        return  a.profit >  b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        //map contains int representing deadline and bool representing whether slot has been occupied or not
        map<int,bool> slots;
        
        //Initially, each slot is unoccupied
        for(int i=1;i<=n;i++){
            slots[i]=false;
        }
        
        //Sort the given array on the basis of profits 
        sort(arr,arr+n,comp);
        
        int ans=0,count=0;
        for(int i=0;i<n;i++){
            int val = arr[i].dead;
            //We have to find the largest value <=deadline, in which we can assign the job
            //We'll make point to the smallest value greater than deadline and decrement the poiter by 1 then
            auto iter = slots.upper_bound(val);
            if(iter!=slots.begin()){
                --iter;
                //Erase that slot from the map
                slots.erase(iter);
                //Add contribution to the ans
                count++;
                ans+=arr[i].profit;
            }
        }
        return {count,ans};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
