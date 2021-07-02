/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*/

class Solution {
public:
    static bool sortPair(pair<int, int>& v1, pair<int, int>& v2) {
        if (v1.second == v2.second) {
            return v1.first < v2.first;
        }
        return v1.second < v2.second;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> closest;
        
        for(int i=0; i<arr.size(); i++) {
            closest.push_back({arr[i], abs(arr[i]-x)});
        }
        
        sort(closest.begin(), closest.end(), sortPair);
        
        // closest.erase(closest.begin()+k, closest.end());
        arr.clear();
        for(int i=0; i<k; i++) {
            arr.push_back(closest[i].first);
        }
        sort(arr.begin(), arr.end());
        return arr;
    }
};
