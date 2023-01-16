/*You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk.
After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxi = 0;
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i< n; ++i){
            maxi = max(maxi, arr[i]);
            if(i == maxi) ans++;
        }
        return ans;
    }
};
