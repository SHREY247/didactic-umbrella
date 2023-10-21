/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi]
indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

  Intuition
To solve this, we model the problem as a directed graph, where each course is a node, and each prerequisite relationship is an edge. If the graph doesn't have any cycles, it means that there is a valid ordering of courses. If there are cycles, it's impossible to complete all the courses.

Approach
1: Create an adjacency list adj to represent the directed graph. adj[i] will store the list of courses that are dependent on course i.
2: Create an indegree array to keep track of how many prerequisites each course has.
3: Create an empty ans vector to store the order in which courses are completed.
4: Iterate through the prerequisites list and populate adj and indegree based on the prerequisites.
5: Start by adding all the courses with an indegree of 0 (those that don't have any prerequisites) to a queue q.
6: While the queue is not empty:
a) Pop a course from the queue.
b) Add it to the ans vector.
c) For each course dependent on the popped course, decrease their indegree by 1.
d) If a dependent course now has an indegree of 0, add it to the queue.

7: After the loop, if the size of ans is equal to the total number of courses n, it means that all courses have been completed, and we can return true. Otherwise, there is a cycle, and it's not possible to complete all courses.

Complexity
Time complexity:
O(V+E)

Space complexity:
O(V+E)

Code
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        vector<int> indegree(n,0);
        vector<int> ans;

        for(auto x:prerequisites){
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> q;
        //Pushing those courses into queue which don't depend on any other course
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto t=q.front();
            ans.push_back(t);
            q.pop();


            for(auto x: adj[t]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        return ans.size()==n;
    }
};
