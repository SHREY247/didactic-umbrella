/*Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. 
You may return the answer in any order.*/

class Solution {
public:
    set<vector<int>> ans; //Set used so that no sequence is repeated
    void solve(vector <int> &nums, int prev, int i,vector<int> &v){
    if(i==nums.size()){
        if(v.size()>=2){
            ans.insert(v);
        }
        return;
    }
    if(nums[i]>=prev){
        v.push_back(nums[i]);
        solve(nums,nums[i],i+1,v);  /*Function called again 4 becomes prev, 6>=4, push 6 and so on*/
        v.pop_back();// Like 7 gets popped out            
    }

    solve(nums,prev,i+1,v);
}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        solve(nums,-101,0,v); /*First we pass i=0, since 4>-101 solve,push nums[i],i.e. 
        4 into v vector*/

        vector<vector<int>> ansa;
        for(auto x:ans){
            ansa.push_back(x);
        }

        return ansa;
    }
};
