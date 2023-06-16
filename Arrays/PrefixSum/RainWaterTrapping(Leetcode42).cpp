/*Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]

Output: 6

Explanation: The above elevation map  is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water  are being trapped.*/

//Approach: Use the prefix max approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        //Vectors to store maximum height at left and right
        vector<int> left(n, 0);  
        vector<int> right(n, 0); 
        
        left[0] = height[0]; 
        right[n-1] = height[n-1];  
        
        // Traversal from left to right to find the maximum height to the left of each element
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i]);  
        }
        
        // Traversal from right to left to find the maximum height to the right of each element
        for (int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i]);  
        }
        
        //Initialize answer to 0
        int ans = 0;
        
        //Deciding height will be the minimum of left and right height
        for (int i = 0; i < n; i++) {
            ans += min(left[i], right[i]) - height[i]; 
        }
        
        return ans;  // Return the total trapped water
    }
};



