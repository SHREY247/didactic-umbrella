/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

 

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
 */


Intuition
The code is implementing a binary search algorithm to find the first bad version among a range of versions from 1 to n. The key assumption here is that the versions are sorted, and there exists a point where versions transition from "good" to "bad".

Approach
1: Initialize low to 1 (the lowest possible version) and high to n (the highest possible version).
2: Perform a binary search:
Calculate mid as the average of low and high.
Check if the version at mid is bad using the isBadVersion function.
If it is bad, then we know the first bad version could be mid or earlier. We check if the version before mid is good (i.e., isBadVersion(mid - 1) is false). If it is, we return mid as the first bad version. Otherwise, we adjust high to continue the search on the left side.
If it is not bad, then the first bad version must be after mid. We adjust low to continue the search on the right side.

Repeat steps 2 until low is less than or equal to high.

Complexity
Time complexity:
O(log n)

Space complexity:
O(1)

Code
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
*/
class Solution {
public:
    int firstBadVersion(int n) {
        long long int low=1, high=n, mid;
        while(low<=high){
        int mid=(low+high)/2;
        if(!isBadVersion(mid)){
            low=mid+1;
        }

        else if(isBadVersion(mid)){
            if((mid-1>=0)  && (!isBadVersion(mid-1) )){
                return mid;
            }
            high=mid-1;
        }
    
    } 
    return mid;            
    }
};
