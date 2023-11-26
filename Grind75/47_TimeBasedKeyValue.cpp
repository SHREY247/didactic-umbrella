/*
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.
Implement the TimeMap class:
TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. 
If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
  
Example 1:
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]
*/

Intuition
1: Create a map for each unique string that is set
2: That map would store the string corresponding to particular timestamps

Approach
1: set() function inserts a new entry or updates an existing one in the map for a given key with the corresponding value and timestamp.
Just add the corresponding entry to the map.

2: get() function retrieves the value associated with a particular key and the nearest lower or equal timestamp. If an exact match for the timestamp is not found, it retrieves the value with the nearest lower timestamp.

Complexity
Time complexity:
O(logN) for both get() and set()

Space complexity:

O(N * M), where N is number of keys and M is number of timestamps

Code
*/


class TimeMap {
public:
    map<string, map<int, string>> mp;
    TimeMap() { 
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)!=mp.end()){
            auto it=mp[key].lower_bound(timestamp);
        
        if(it->first==timestamp){
            return it->second;
        }  

        it--;
        if(it->first < timestamp){
            return it->second;
        }
        }
        return "";      
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
