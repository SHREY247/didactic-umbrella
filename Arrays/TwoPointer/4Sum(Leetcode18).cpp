/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        
        //Sort the nums vector
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {       
                //To ensure uniqueness of the first element (a)
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            else
            {
                for (int j = i + 1; j < n; j++)
                {   
                    //To ensure uniqueness of b
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                    else
                    {   
                        //Since we have fixed a and b, so the remaining sum is = target - (a+b)
                        long long int rem = (long long)target - ((nums[i]+nums[j]));

                 //Use 2 pointer approach on the remaining vector to find such 2 elements with sum = rem
                        int s = j + 1, e = nums.size() - 1;
                        while (s < e)
                        {
                            if (nums[s] + nums[e] < rem) s++;
                            else if (nums[s] + nums[e] > rem) e--;
                            else
                            {
                                vector<int> vec;
                                vec.push_back(nums[i]);
                                vec.push_back(nums[j]);
                                vec.push_back(nums[s]);
                                vec.push_back(nums[e]);
                                ans.push_back(vec);

                                //If nums[s]==nums[e], no more unique pair can be found, so break
                                if (nums[s] == nums[e]) break;
                                else
                                {   
                                    //Until you find same value of nums[s] keep on incrementing s 
                                    int x = nums[s], y = nums[e];
                                    while (nums[s] == x) s++;

                                    //Until you find same value of nums[e] keep on decrementing e 
                                    while (nums[e] == y) e--;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};



 
