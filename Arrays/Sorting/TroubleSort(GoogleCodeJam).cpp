/*
perform bubble sort with three elements at a time and, if the last element in the triplet bigger then the first,
one reverses the entire 3-element sub-list. Pseudo-code for this algorithm was given. The goal of the exercise was to, 
given a list, sort that list using above strategy and then asserting that it was ordered.
If it was one should print “OK” otherwise one should print the index of the (0-indexed) first element of non-increasing order (e.g. [3,9,7] should return 1).
*/  


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
void troubleSort(vector<int> &v, int n){
    vector<int>even;
    vector<int>odd;
    for(int i=0; i<=n-1; i++){
        if(i%2 ==0){
            even.push_back(v[i]);
        }
        else{
            odd.push_back(v[i]);
        }
    }
 
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
 
    int e =0, o =0;
    for(int i=0; i<=n-1; i++){
        if(i%2 ==0){
            v[i] = even[e];
            e++;
        }
        else{
            v[i] = odd[o];
            o++;
        }
    }
}
 
int ansGenerator(vector<int> &v, int n){
    troubleSort(v,n);
    for(int i=0; i<n-1; i++){
        if(v[i] > v[i+1]){
            return i;
            break;
        }
    }
    return -1;
}
 
int main(){
    int T;
    cin >> T;
 
    int case_var =1;
    while(T){
        int n; 
        cin >> n;
 
        vector<int> v(n);
        for(int i=0 ; i<n; i++){
            cin >> v[i];
        }
 
        int ans = ansGenerator(v, n);
        if(ans != -1) {
            cout << "Case #" << case_var << ": "<<  ans << endl;
        }else {
            cout << "Case #" << case_var<< ": "<<  "OK" << endl;
        }
        case_var++;
        T--;
    }
}
