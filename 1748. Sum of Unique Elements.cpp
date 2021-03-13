/*
You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.

Return the sum of all the unique elements of nums.


Example 1:

Input: nums = [1,2,3,2]
Output: 4
Explanation: The unique elements are [1,3], and the sum is 4.

Example 2:

Input: nums = [1,1,1,1,1]
Output: 0
Explanation: There are no unique elements, and the sum is 0.
*/



class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        int ans=0;
        for(auto x : mp){
            if(x.second == 1) {
                ans += x.first;
            }
        }
        return ans;
    }
};
