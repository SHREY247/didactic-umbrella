/*A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. 
Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;   //left would have max weight
        int right = 0; //Right would have sum of all weights
        for(int i : weights){
            left = max(left, i);
            right += i;
        }
        int mid;
        int ans = right;
        //Implementation of binary search
        while(left <= right){
            mid = (left + right) / 2;
            if(check(weights, days, mid)){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    
    //check if required days is less than equal to days 
    bool check(vector<int>& weights, int days, int capacity){
        int requiredDays = 1;
        int currWeight = 0;
        for(int i : weights){
            if(currWeight + i > capacity){
                requiredDays++;
                currWeight = 0;
            }
            currWeight += i;
        }
        if(requiredDays > days) return false;
        return true;
    }
};
