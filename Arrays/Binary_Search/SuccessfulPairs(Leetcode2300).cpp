/*You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.
*/

/*# Intuition
Brute force solution would take a huge time complexity for large number of values, so we need to come up with a better solution

# Approach
We need to use binary search:
1) First sort potions
2) If product of potions[i] with middle element is less than success, ignore the left part of the array and update start as s=mid+1
3) If product of potions[i] with middle element is greater than success, the whole right part would be in answer so count += e-mid+1 and also check the left elements now. For that, update e=mid-1
# Complexity
- Time complexity:
O(NlogN)

- Space complexity:
O(N)*/

//Code:
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        int p =potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(long long i : spells){

            int s=0;
            int e=p-1;
            int count=0;
            //Binary search
            while(s<=e){
                int mid=s+(e-s)/2;
                if(i*potions[mid]>=success){
                    count+=e-mid+1;   
                    e=mid-1;
                }
                else if(i*potions[mid]<success){
                    s=mid+1;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

