/*You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
Return the average salary of employees excluding the minimum and maximum salary.
Answers within 10-5 of the actual answer will be accepted.

Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500*/

/*Intuition
Just sort the salaries and compute average after removing minimum and maximum salaries

Approach
1: Sort the given salary array
2: Just start computing the sum from 2nd element until the second last element, thereby, removing the minimum as well as maximum element from the computation of sum.
4: Average would be equal to sum/(n-2) (Where n represents total size of salary array and subtracting 2 as we don't consider 2 elements(Minimum and maximum ones)

Complexity
Time complexity:
O(N*LogN)

Space complexity:
O(1)*/

class Solution {
public:
    double average(vector<int>& salary) {
        double n=salary.size();
        double sum=0,ans=0;
        sort(salary.begin(),salary.end());
        for(double i=1;i<n-1;i++){
            sum+= salary[i];
        }
        ans=sum/(n-2);

        return ans;
    }
};
