/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Intuition
In C++, priority queue is generally a max heap, but here we need a min heap so we push the negative of distances into it

Approach
1: priority_queue<pair<int,int>> pq; declares a priority queue named pq that stores pairs of integers. In this case, each pair will represent a distance and the index of a point.

2: The loop for(int i = 0;i<p.size();i++) iterates over all the points in the input vector p.

3: Inside the loop, the code calculates the squared distance of each point from the origin using the formula dist = p[i][0]*p[i][0]+p[i][1]*p[i][1]. This is essentially the square of the Euclidean distance.

4: pq.push({-1*dist,i}); adds a pair to the priority queue.

5: After the loop, vector<vector> ans; declares a 2D vector ans to store the k closest points.

6: The following loop while(k--) iterates k times:
a) auto x = pq.top(); retrieves the top element (smallest distance) from the priority queue and assigns it to the variable x.
b) pq.pop(); removes the top element from the priority queue.
c) ans.push_back(p[x.second]); adds the corresponding point (using the index x.second) to the ans vector.

7: Finally, the method returns the vector ans containing the k closest points.

Complexity
Time complexity:
O((N+K)log N)
O(NlogN) because of the N push operations into the priority queue having log N complexity each
O(KlogN) because of top and pop operations in the last while loop,

Space complexity:
O(N+K)
O(N): priority queue size
O(K): size of ans vector

Code
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<p.size();i++)
        {
            int dist = p[i][0]*p[i][0]+p[i][1]*p[i][1];
            pq.push({-1*dist,i});
        }
        vector<vector<int>> ans;
        while(k--)
        {
            auto x = pq.top();
            pq.pop();
            ans.push_back(p[x.second]);
        }
        return ans;   
    }
};

