/*You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.

Example:
Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.*/

/*Approach
1: We can partition into a chunk only when we find out the minimum element while traversing, for example, until we don't find 0 we can't chunk
2: So, basically we'll be creating a prefixmax array and will be computing the prefix max uptil index i
3: Then, in the prefixmax array, we'll find out the point where prefixmax[i]==i because at that point we would be having all the elements from 0 uptil i in that chunk and we can increase the count of the chunk
4: Return chunk*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int prefixmax[n];
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(max<arr[i]){
                max=arr[i];
            }
            prefixmax[i]=max;
        }

        int chunk=0;
    
        for(int i=0;i<n;i++){
            if(prefixmax[i]==i){
            chunk++;
        }
    }
    return chunk;
    }

};
