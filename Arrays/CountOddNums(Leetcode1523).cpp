//Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
/*Solution:
l:low, h:high
//Answer = (Total odd number between 1 and high), i.e., (high+1)/2 - (Total odd number between 1 and low - 1), i.e. low/2
//This is because we have to add both high and lower number */

class Solution {
public:
    int countOdds(int l, int h) {
        return ((h + 1) / 2) - (l / 2);
    }
};

