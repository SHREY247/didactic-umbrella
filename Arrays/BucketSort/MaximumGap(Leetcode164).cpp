/*Given an integer array nums, return the maximum difference between two successive elements in its sorted form.
If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.**
  

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        // if number of elements are 1 or 2 only
        if(n == 1)
            return 0;
        if(n == 2)
            return abs(nums[0]-nums[1]);

        // storing maximum value and minimum value
        int maxi = nums[0];
        int mini = nums[0];
        for(int i=1; i<n; i++){
            maxi = max(maxi, nums[i]);
            mini= min(mini, nums[i]);
        }

        // Dividing the problem into multiple buckets
        //Each bucket size calculated with below formula:
        int bucketSize = ceil(float(maxi-mini)/(n-1));
        // bucket size will be zero if all elements are same, then max gap is 0
        if(bucketSize == 0)
            return 0;
        
        int numOfBuckets = n;

        //made vectors to store the max and min value of each bucket
        vector<int> maxOfBucket(numOfBuckets, INT_MIN);
        vector<int> minOfBucket(numOfBuckets, INT_MAX);

        // checking in which bucket element will fall, updating the max and min value of bucket if possible
        for(int i=0; i<n; i++){
            int ele = nums[i];
            int Bucketnumber = ((ele - mini)/bucketSize);

            maxOfBucket[Bucketnumber] = max(maxOfBucket[Bucketnumber], ele); 
            minOfBucket[Bucketnumber] = min(minOfBucket[Bucketnumber], ele);
        }

        // finally answer will be atleast the bucketSize or greater
        int ans = bucketSize;

        // stored previous max, to find the max gap with the curr buckets minimum
        int prevMax = maxOfBucket[0];
        for(int i=1; i<numOfBuckets; i++){
            //because there can be buckets in between with no elements
            if(minOfBucket[i] == INT_MAX)
                continue;

            ans = max(ans, (minOfBucket[i]-prevMax));
            prevMax = maxOfBucket[i];
        }

        // final answer, max gap
        return ans;
    }
};

 
