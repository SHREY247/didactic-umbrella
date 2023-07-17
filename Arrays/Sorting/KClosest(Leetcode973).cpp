/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/

class Solution {
public:

    struct Triplet{
        int x;
        int y;
        int d;
    };
    
    //Comparator
    static bool cmp(Triplet t1, Triplet t2){
        return t1.d < t2.d;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector <Triplet> v(n);
        for(int i = 0; i < n; i++){

            v[i].x = points[i][0];   //x coordinate
            v[i].y = points[i][1];   //y coordinate
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1]; //calculate distance
            v[i].d = d; 
        }
        
        sort(v.begin(), v.end(), cmp);
        vector <vector <int>> res;
        for(int i = 0; i < k; i++){
           res.push_back({v[i].x,v[i].y});
        }

        return res;
    }
};

